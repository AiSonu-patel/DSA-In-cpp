#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Connect Graph
// Depth-First Search (DFS) Traversal
// Time Complexity O(v+e)
// Space Complexity O(v)

void DFS(int node, vector<vector<int>>&adj, vector<int>&ans, vector<bool>&visited)
{
    visited[node]=1;
    ans.push_back(node);

    for(int j=0; j<adj[node].size(); j++)
    {
        if(!visited[adj[node][j]])
        DFS(adj[node][j], adj, ans, visited);
    }
};

vector<int> dfsOfGraph(vector<vector<int>>&adj)
{
    int v = adj.size();
    vector<bool>visited(v,0);
    vector<int>ans;
    DFS(0, adj, ans, visited);

    return ans;
};

int main()
{
    // vector<vector<int>>adj = {{2,3,1},{0},{0,4},{0},{2}}; // output -> 0 2 4 3 1
    vector<vector<int>>adj = {{1,2},{0,2},{0,1,3,4},{2},{2}}; // output -> 0 1 2 3 4

    vector<int>ans = dfsOfGraph(adj);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}