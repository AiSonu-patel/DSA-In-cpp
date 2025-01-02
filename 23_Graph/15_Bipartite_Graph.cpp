#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// DFS
// Bipartite Graph (2-Coloring Algorithm)
/*
    It is a graph in which the vertices can be divided into two dis joint set, Such that no 2 vertices
    within the some set are adjacent. It other words, it is a graph in which every edge connect a
    vertex of one set to a vertex of other set.
*/

// Time Complexity O(V+E)
// Space Complexity O(V)

bool checkBip(int node, vector<vector<int>>&adj, vector<int>&color)
{
    // look at each neighbour
    for(int j=0; j<adj[node].size(); j++)
    {
        // color is not assigned to the neighbour
        if(color[adj[node][j]]==-1)
        {
            color[adj[node][j]] = (color[node]+1)%2;
            if(!checkBip(adj[node][j], adj, color))
            return 0;
        }
        // color is assigned
        else
        {
            if(color[node]==color[adj[node][j]])
            return 0;
        }
    }
    return 1;
}

bool isBipartite(vector<vector<int>>&adj)
{
    int v = adj.size();
    vector<int>color(v, -1);
    for(int i=0; i<v; i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            if(!checkBip(i, adj, color))
            return 0;
        }
    }
    return 1;
    
}

int main()
{
    // vector<vector<int>>adj = {{}, {3}, {3}, {}, {0, 1}, {0, 2}}; // output = 0
    vector<vector<int>>adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}; // output = 1
    cout<<isBipartite(adj);
}