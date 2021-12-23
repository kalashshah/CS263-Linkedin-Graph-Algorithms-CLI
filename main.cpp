#include <bits/stdc++.h>
using namespace std;
// details class
class detailsOfUser
{
public:
    // static const int idOfUser = 0;
    string name;
    string profession;
    int experience;
    vector<string> skills;
    string bio;
    int id;

    detailsOfUser(string name, string profession, int exp, vector<string> skills, string bio, int idd)
    {
        this->name = name;
        this->profession = profession;
        experience = exp;
        this->skills = skills;
        this->bio = bio;
        this->id = idd;
        // cout<<this->id<<"\n";
    }

    void printDetails()
    {
        cout << "NAME: " << name << "\n";
        cout << "PROFESSION: " << profession << "\n";
        cout << "EXPERIENCE: " << experience << "\n";
        cout << "SKILLS: ";
        for (int i = 0; i < skills.size(); i++)
        {
            cout << skills[i] << " ";
        }
        cout << "\nBIO: " << bio << "\n";
    }
};
// Global adjacency list to store the user data
vector<vector<detailsOfUser>> adjList(6);

void addConnection(detailsOfUser d1, detailsOfUser d2)
{
    // here we have some unique id given to each user and we are pushing that to each others adjacency list
    // to make a connection....
    adjList[d1.id].push_back(d2);
    adjList[d2.id].push_back(d1);
    // for(auto x: adjList[d1.id]){
    //     cout<<x.name<<" ";
    // }
    // cout<<"\n*************"<<"\n";
}

// Utility Function
void dfs(vector<vector<detailsOfUser>> &matrix, vector<bool> &visited, detailsOfUser sv)
{
    cout << sv.name << "\n";
    visited[sv.id] = true;

    for (auto x : matrix[sv.id])
    {
        if (!visited[x.id])
        {
            dfs(matrix, visited, x);
        }
    }
}
int main()
{
    vector<bool> visited(6, false);
    vector<string> skills = {"WebDevelopment", "Flutter"};
    // Let us make a predefined class
    detailsOfUser Dhruv("Dhruv", "Software Developer", 10, skills, "I am a software Developer",0);
    detailsOfUser Kalash("Kalash", "React Developer", 10, skills, "I am React Developer.",1);
    detailsOfUser Brijesh("Brijesh", "DSA Mentor", 9, skills, "I love exploring DS and Algos",2);
    detailsOfUser Dhyey("Dhyey", "Flutter Developer", 8, skills, "I am Flutter Developer",3);
    detailsOfUser Parth("Parth", "Designer", 10, skills, "I am interested in designing",4);
    detailsOfUser Shrey("Shrey", "Developer", 10, skills, "I am also interested in development",5);

    // Now we have our initial seeds ready now we will work with the graph
    addConnection(Dhruv, Kalash);
    addConnection(Dhruv, Brijesh);
    addConnection(Kalash, Parth);
    addConnection(Parth, Dhyey);
    addConnection(Shrey, Dhruv);
    addConnection(Brijesh, Kalash);

    // This is our basic connection i.e., till here we are creating friend connection and storing data in a node....
    // dfs(adjList,visited,Dhruv);
    return 0;
}