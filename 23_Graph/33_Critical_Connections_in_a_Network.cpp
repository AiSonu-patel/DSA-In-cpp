#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(V+E)
// Space Complexity O(V+E)

void DFS(int node, int parent, vector<vector<int>>&adj, vector<int>&disc, vector<int>&low, vector<bool>&visited, vector<vector<int>>&Bridges, int &count)
{
    disc[node] = low[node] = count;
    visited[node] = 1;

    for(int j=0; j<adj[node].size(); j++)
    {
        int neb = adj[node][j];
        if(neb == parent)
        continue;
        else if(visited[neb])
        {
            low[node] = min(low[node], low[neb]);
        }
        else
        {
            count++;
            DFS(neb, node, adj, disc, low, visited, Bridges, count);
            // Bridges exist
            if(low[neb]>disc[node])
            {
                vector<int>temp;
                temp.push_back(node);
                temp.push_back(neb);
                Bridges.push_back(temp);
            }

            low[node] = min(low[node], low[neb]);
        }
    }
};

vector<vector<int>> criticalConnections(int n, vector<vector<int>>&connections)
{
    vector<vector<int>>adj(n);
    for(int i=0; i<connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>>Bridges;
    vector<int>disc(n); // Discovery time
    vector<int>low(n); // low time
    vector<bool>visited(n, 0);
    int count = 0;

    DFS(0, -1, adj, disc, low, visited, Bridges, count);

    return Bridges;
};

int main()
{
    vector<vector<int>>connections = {{0,1},{1,2},{2,0},{1,3}}; // output {{1,3}}
    int n = 4;
    vector<vector<int>>ans = criticalConnections(n, connections);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[0].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}