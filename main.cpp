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
};
// Global adjacency list to store the user data
vector<vector<detailsOfUser>> adjList(16);

void addConnection(detailsOfUser d1, detailsOfUser d2)
{
    adjList[d1.id].push_back(d2);
    adjList[d2.id].push_back(d1);
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