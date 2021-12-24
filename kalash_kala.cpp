#include <bits/stdc++.h>
#include "main.cpp"

using namespace std;

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
    
    for(int i=0; i<adjList[vertex].size(); i++){
        
        if(adjList[vertex][i].id==parents[vertex]){
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
