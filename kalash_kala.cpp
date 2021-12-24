
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <stack>
#include <map>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <deque>
#include <queue>
#include <list>
#include <iomanip>
#include <numeric>


#define MULTIPLY(a, b) a*b
#define MOD 1000000007
#define MAX 100001
#define pb push_back
#define I INT_MAX
#define N 100005

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

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
    }
};

bool operator< (const detailsOfUser &left, const detailsOfUser &right)
{
    return left.id < right.id;
}

bool operator== (const detailsOfUser &left, const detailsOfUser &right)
{
    return left.id == right.id;
}

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
    
    parents[vertex] = parent;
    colour[vertex] = 1;
    
    // if colour is 0 then start exploring this person
    
    for(int i=0; i<adjList[vertex].size(); i++){
        
        if(adjList[vertex][i].id==parents[vertex]){
            continue;
        }
        suggestedCycle(adjList[vertex][i].id,vertex,colour,mark,parents,totalCycles);
    }
    
    // after all exploration is done then we assign the colour of this vertex as 2
    colour[vertex] = 2;
}

void showSuggestedCycles(int* mark, int totalCycles, int people, unordered_map<int, string> ump){
    
    for(int i=0; i<people; i++){
        if(mark[i]!=0){
            cycles[mark[i]].push_back(i);
        }
    }
    
    for(int i=1; i<=totalCycles; i++){
        for(int x : cycles[i]){
            cout<<ump[x]<<" ,";
        }
        cout<<"\n";
    }
    
}


int main(int argc, const char * argv[]) {
    
    unordered_map<int, string> ump;
    
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
    ump[0] = User1.name;
    detailsOfUser User2("Kalash Shah", "React Developer", 10, skills2, "I am React Developer.", 1);
    ump[1] = User2.name;
    detailsOfUser User3("Brijesh", "DSA Mentor", 9, skills3, "I love exploring DS and Algos", 2);
    ump[2] = User3.name;
    detailsOfUser User4("Dhyey", "Software Developer", 8, skills4, "I am Flutter Developer", 3);
    ump[3] = User4.name;
    detailsOfUser User5("Parth", "Designer", 10, skills5, "I am interested in designing", 4);
    ump[4] = User5.name;
    detailsOfUser User6("Hritik", "Software Developer", 5, skills6, "I am also interested in development", 5);
    ump[5] = User6.name;
    detailsOfUser User7("Kalash Kala", "Software Developer", 8, skills7, "I am also interested in development", 6);
    ump[6] = User7.name;
    detailsOfUser User8("Gyan", "React Developer", 10, skills8, "I am also interested in development", 7);
    ump[7] = User8.name;
    detailsOfUser User9("Jay", "DSA Mentor", 10, skills9, "I am also interested in development", 8);
    ump[8] = User9.name;
    detailsOfUser User10("Kewal", "Web Developer", 10, skills10, "I am also interested in development", 9);
    ump[9] = User10.name;
    detailsOfUser User11("User 11", "Flutter", 4, skills11, "I am also interested in development", 10);
    detailsOfUser User12("User 12", "ML/AI", 2, skills12, "I am also interested in development", 11);
    detailsOfUser User13("User 13", "UI/UX", 9, skills13, "I am also interested in development", 12);
    detailsOfUser User14("User 14", "Embedded Systems", 10, skills14, "I am also interested in development", 13);

    detailsOfUser User15("User 15", "Software Developer", 10, skills15, "I am also interested in development", 14);
    detailsOfUser User16("User 16", "Flutter", 8, skills16, "I am also interested in development", 15);
    
    

    addConnection(User1, User2);
    addConnection(User2, User4);
    addConnection(User4, User3);
    addConnection(User3, User1);
    addConnection(User2, User5);
    addConnection(User5, User6);
    addConnection(User6, User9);
    addConnection(User9, User8);
    addConnection(User8, User7);
    addConnection(User7, User10);
    addConnection(User7, User6);
    
    int colour[N] = {0};
    int parents[N] = {0};
 
    int mark[N] = {0};
 

    int cyclenumber = 0;
    int edges = 11;
    
    suggestedCycle(User1.id, -1, colour, mark, parents, cyclenumber);
    showSuggestedCycles(mark, cyclenumber, edges, ump);
    
    return 0;
}
