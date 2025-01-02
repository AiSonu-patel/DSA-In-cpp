#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Topological Sorting for a DAG is a linear ordering of vertices such that for every directed edge
// u -> v, the vertex u comes before v.

// Topological Sort (Directed Acyclic Graph (DAG))
// Time Complexity O(V+E)
// Space Complexity O(V)
// Using BFS Traversal (Kahn's Algo)

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> res;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (int nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for (int nbr : adj[curr])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return res;
}

int main()
{
    // vector<vector<int>> adj = {{}, {0}, {0}, {0}}; // output 1 2 3 0
    vector<vector<int>> adj = {{}, {3}, {3}, {}, {0, 1}, {0, 2}}; // output 4 5 1 0 2 3

    vector<int> ans = topologicalSort(adj);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}