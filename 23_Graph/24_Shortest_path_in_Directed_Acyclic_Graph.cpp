#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

// Shortest path in Directed Acyclic Graph
// Time Complexity O(V+E)
// Space Complexity O(V+E)

void DFS(int node, stack<int>&s, vector<bool>&visited, vector<pair<int,int>>adj[])
{
    visited[node]=1;
    for(int j=0; j<adj[node].size(); j++)
    {
        if(!visited[adj[node][j].first])
        DFS(adj[node][j].first, s, visited, adj);
    }

    s.push(node);
};

vector<int> shortestPath(int N, int M, vector<vector<int>>&edges)
{
    // Adjacency List
    vector<pair<int, int>>adj[N];
    for(int i=0; i<M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj[u].push_back(make_pair(v, weight));
    }
    // Topological sort (DFS)
    stack<int>s;
    vector<bool>visited(N,0);
    DFS(0, s, visited, adj);
    vector<int>dist(N, INT_MAX);
    dist[0]=0;

    // stack empty
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        for(int j=0; j<adj[node].size(); j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;
            dist[neighbour] = min(dist[neighbour], weight+dist[node]);
        }
    }

    // -1
    for(int i=0; i<N; i++)
    {
        if(dist[i]==INT_MAX)
        dist[i] = -1;
    }

    return dist;
}

int main()
{
    int N = 4, M = 2;
    vector<vector<int>>edges = {{0,1,2},{0,2,1}};

    vector<int> ans = shortestPath(N, M, edges);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" "; // 0 2 1 -1
}