#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;

class gyanBabu
{
public:
	// Search users with profession in adjList using BFS
	vector<detailsOfUser> search(vector<vector<detailsOfUser>> &adjList, string value, int userID)
	{
		vector<detailsOfUser> particularUsers;
		queue<int> q;
		q.push(userID);
		vector<bool> visited(16, false);
		visited[userID] = true;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto x : adjList[u])
			{
				if (!visited[x.id])
				{
					if (x.profession == value)
					{
						particularUsers.push_back(x);
					}
					q.push(x.id);
					visited[x.id] = true;
				}
			}
		}
		return particularUsers;
	}

	// Search if user with given name exists in adjList
	bool findUserByName(vector<vector<detailsOfUser>> &adjList, string value, int userID)
	{
		queue<int> q;
		q.push(userID);
		vector<bool> visited(16, false);
		visited[userID] = true;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto x : adjList[u])
			{
				if (!visited[x.id])
				{
					if (x.name == value)
					{
						return true;
					}
					q.push(x.id);
					visited[x.id] = true;
				}
			}
		}
		return false;
	}
};

int main()
{
	vector<string> skills1 = {"Web Developer", "Flutter"};
	vector<string> skills2 = {"Web Developer", "Flutter", "React"};
	vector<string> skills3 = {"Web Developer", "Flutter", "DSA"};
	vector<string> skills4 = {"Web Developer", "Flutter", "JAVA"};
	vector<string> skills5 = {"Web Developer", "Flutter", "Algo"};
	vector<string> skills6 = {"Web Developer"};
	vector<string> skills7 = {"Web Developer", "BlockChain Developer"};
	vector<string> skills8 = {"Android", "IOS Swift"};
	vector<string> skills9 = {"Web Developer", "Flutter", "CPP"};
	vector<string> skills10 = {"Web Developer", "Flutter", "DSA"};

	detailsOfUser User1("Dhruv", "Software Developer", 10, skills1, "I am a software Developer", 0);
	detailsOfUser User2("Kalash Shah", "React Developer", 10, skills2, "I am React Developer.", 1);
	detailsOfUser User3("Brijesh", "DSA Mentor", 9, skills3, "I love exploring DS and Algos", 2);
	detailsOfUser User4("Dhyey", "Software Developer", 8, skills4, "I am Flutter Developer", 3);
	detailsOfUser User5("Parth", "Designer", 10, skills5, "I am interested in designing", 4);
	detailsOfUser User6("Hritik", "Software Developer", 5, skills6, "I am also interested in development", 5);
	detailsOfUser User7("Kalash Kala", "Software Developer", 8, skills7, "I am also interested in development", 6);
	detailsOfUser User8("Gyan", "React Developer", 10, skills8, "I am also interested in development", 7);
	detailsOfUser User9("Jay", "DSA Mentor", 10, skills9, "I am also interested in development", 8);
	detailsOfUser User10("Kewal", "Web Developer", 10, skills10, "I am also interested in development", 9);

	addConnection(User1, User2);
	addConnection(User1, User3);
	addConnection(User2, User5);
	addConnection(User5, User4);
	addConnection(User2, User7);
	addConnection(User7, User8);
	addConnection(User8, User6);
	addConnection(User6, User1);
	addConnection(User9, User10);
	addConnection(User1, User9);

	// Enter profession to search
	string profession;
	cout << "Enter profession to search: ";
	std::getline(std::cin, profession);
	gyanBabu gb;
	auto ans = gb.search(adjList, profession, 0);
	for (auto it : ans)
	{
		cout << it.name << endl;
	}

	// Enter name to search
	string name;
	cout << "Enter name to search: ";
	std::getline(std::cin, name);
	auto ans1 = gb.findUserByName(adjList, name, 0);
	if (ans1)
	{
		cout << "User found" << endl;
	}
	else
	{
		cout << "User not found" << endl;
	}
	return 0;
}