#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;

class kewalAlgo
{
public:
    vector<detailsOfUser> particularUsers;

    void sortExpUtil(vector<vector<detailsOfUser>> &v, vector<bool> &visited, int userID, string value)
    {
        bool a = false;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j].id == userID)
                {
                    for (int k = 0; k < particularUsers.size(); k++)
                    {
                        if (particularUsers[k].id == v[i][j].id)
                        {
                            a = true;
                            break;
                        }
                    }
                    if (!a)
                    {
                        if (v[i][j].profession == value)
                        {
                            particularUsers.push_back(v[i][j]);
                        }
                    }
                }
                if(a){
                    break;
                }
            }
            if(a){
                break;
            }
        }

        visited[userID] = true;
        for (auto x : v[userID])
        {
            if (!visited[x.id])
            {
                sortExpUtil(v, visited, x.id, value);
            }
        }
    }

    void sortExp(vector<vector<detailsOfUser>> &v, string value)
    {
        vector<bool> visited(16, false);

        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                sortExpUtil(v, visited, i, value);
            }
        }
    }

    void finalSolver()
    {
        for (int i = 0; i < particularUsers.size(); i++)
        {
            for (int j = i + 1; j < particularUsers.size(); j++)
            {
                if (particularUsers[i].experience < particularUsers[j].experience)
                {
                    detailsOfUser temp = particularUsers[i];
                    particularUsers[i] = particularUsers[j];
                    particularUsers[j] = temp;
                }
            }
        }

        for (int i = 0; i < particularUsers.size(); i++)
        {
            cout << particularUsers[i].name << "->"<< particularUsers[i].experience<< "\n";
        }
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

    vector<string> skills11 = {"Web Developer", "Flutter"};
    vector<string> skills12 = {"Web Developer", "Flutter", "ML/AI"};
    vector<string> skills13 = {"ML/AI"};
    vector<string> skills14 = {"Web Developer", "React Developer"};

    vector<string> skills15 = {"Web Developer", "Flutter"};
    vector<string> skills16 = {"Web Developer", "DSA"};

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

    detailsOfUser User11("User 11", "Flutter", 4, skills11, "I am also interested in development", 10);
    detailsOfUser User12("User 12", "ML/AI", 2, skills12, "I am also interested in development", 11);
    detailsOfUser User13("User 13", "UI/UX", 9, skills13, "I am also interested in development", 12);
    detailsOfUser User14("User 14", "Embedded Systems", 10, skills14, "I am also interested in development", 13);

    detailsOfUser User15("User 15", "Software Developer", 10, skills15, "I am also interested in development", 14);
    detailsOfUser User16("User 16", "Flutter", 8, skills16, "I am also interested in development", 15);

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

    addConnection(User11, User12);
    addConnection(User12, User13);
    addConnection(User13, User14);

    addConnection(User15, User16);

    // enter a profession and sort it according to the experience
    cout << "Enter profession"
         << "\n";
    string profession;
    cin.clear();
    cin.sync();
    getline(cin, profession);

    kewalAlgo kewal;
    kewal.sortExp(adjList, profession);
    kewal.finalSolver();

    return 0;
}