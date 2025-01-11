// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Auxiliary Space: O(V + E)

void Topological(int node, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&s)
{
    visited[node]=1;

    for(int i=0; i<adj[node].size(); i++)
    {
        if(!visited[adj[node][i]])
        Topological(adj[node][i], adj, visited, s);
    }

    s.push(node);
};

void DFS(int node, vector<vector<int>>&adj2, vector<bool>&visited)
{
    visited[node] =1;
    for(int j=0; j<adj2[node].size(); j++)
    {
        if(!visited[adj2[node][j]])
        DFS(adj2[node][j], adj2, visited);
    }
};

int kosaraju(int V, vector<vector<int>>&adj)
{
    // Topological sort
    stack<int>s;
    vector<bool>visited(V,0);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        Topological(i, adj, visited, s);
    };

    // reverse the edges / Transpose the graph
    vector<vector<int>>adj2(V);
    for(int i=0; i<V; i++)
    for(int j=0; j<adj[i].size(); j++)
    {
        int u = i;
        int v = adj[i][j];
        adj2[v].push_back(u);
    }

    // pop the element from stack
    for(int i=0; i<V; i++)
    visited[i]=0;

    int scc = 0;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        // if popped node is not visited yet 
        if(!visited[node])
        {
            // scc++
            scc++;
            // DFS
            DFS(node, adj2, visited);
        }
    }
    return scc;
    
};

int main()
{
    vector<vector<int>>adj = {{2,3},{0},{1},{4},{}};
    int V = adj.size();
    cout<<kosaraju(V, adj); // 3
}