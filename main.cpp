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
vector<vector<detailsOfUser>> adjList(10);


int mark[100000] = {0};
vector<vector<int>> cycles(100000);

void suggestedCycle(int vertex, int parent, int* colour, int* mark, int* parents, int& totalCycles){
    
    // colour 2 means that all the connections of that person has been explored
    if(colour[vertex]==2){
        return;
    }
    
    /*
     colour 1 means that the current connection is being explored, if during exploration we reach
     a person whose colour is 1 then this implies that there is a cycle
     */
    
    if(colour[vertex]==1){
        
        totalCycles++;
        int cur = parent;
        mark[parent] = totalCycles;
        
        while(cur!=vertex){
            cur = parents[cur];
            mark[cur] = totalCycles;
        }
        
        return;
    }
    
    // if colour is 0 then start exploring this person
    
    for(int i=0; i<6; i++){
        
        if(adjList[i].id==parents[vertex]){
            continue;
        }
        suggestedCycle(adjList[i].id,vertex,colour,mark,parents,totalCycles);
    }
    
    // after all exploration is done then we assign the colour of this vertex as 2
    colour[vertex] = 2;
}

void showSuggestedCycles(int* mark, int totalCycles, int people){
    
    for(int i=0; i<people; i++){
        if(mark[i]!=0){
            cycles[mark[i]].push_back(i);
        }
    }
    
    for(int i=1; i<=totalCycles; i++){
        for(int x : cycles[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    
}

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
