#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Topological Sorting for a DAG is a linear ordering of vertices such that for every directed edge
// u -> v, the vertex u comes before v.

// Topological Sort (Directed Acyclic Graph (DAG))
// Time Complexity O(V+E)
// Space Complexity O(V)

void DFS(int node, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&s)
{
    visited[node]=1;
    for(int j=0; j<adj[node].size(); j++)
    {
        if(!visited[adj[node][j]])
        DFS(adj[node][j], adj, visited, s);
    }

    s.push(node);
};

vector<int> topologicalSort(vector<vector<int>>&adj)
{
    int v = adj.size();
    vector<bool>visited(v, 0);
    stack<int>s;

    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        DFS(i, adj, visited, s);
    }

    vector<int>ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
    
}

int main()
{
    vector<vector<int>>adj = {{},{0},{0},{0}}; // output 3 2 1 0 
    // vector<vector<int>>adj = {{},{3},{3},{},{0,1},{0,2}}; // output 5 4 2 1 3 0

    vector<int>ans = topologicalSort(adj);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}