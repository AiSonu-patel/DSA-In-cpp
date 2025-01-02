#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Detect Cycle in an Undirected Graph
// DFS Traversal
// Time Complexity O(v+e)
// Space Complexity O(v)

bool cycleDetect(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = 1;
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (parent == adj[node][j])
            continue;
        if (visited[adj[node][j]])
            return 1;
        if (cycleDetect(adj[node][j], node, adj, visited))
            return 1;
    }
    return 0;
};

bool isCycle(vector<vector<int>> &adj)
{
    int v = adj.size();
    vector<bool> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && cycleDetect(i, -1, adj, visited))
            return 1;
    }
    return 0;
};

int main()
{
    // vector<vector<int>> adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}; // output 1
    vector<vector<int>> adj = {{}, {2}, {1, 3}, {2}}; // output 0
    cout << isCycle(adj);
}