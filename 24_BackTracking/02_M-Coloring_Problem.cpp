#include <bits/stdc++.h>
using namespace std;

bool DFS(int node, vector<int> &color, vector<vector<int>>adj, int n, int m)
{
    //  Try each color one by one
    for (int i = 0; i < m; i++)
    {
        // No Adjacent node should have this color
        bool isPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (adj[node][j] && color[i]==i)
            {
                isPossible = 0;
                break;
            }
        }

        if(isPossible==0)
        continue; // Check the next color

        color[node] = i;
        // Assign color to the node
        isPossible = 1;
        // Go to the adjacent node, whom the color is not assigned
        for(int j=0; j<n; j++)
        {
            if(adj[node][j] && color[j]==-1)
            {
                if(!DFS(j, color, adj, n, m))
                {
                    isPossible = 0;
                    break;
                }
            }
        }

        if(isPossible)
        return 1;

        color[node] = -1;
    }

    return 0;
};

bool graphColoring(int n, vector<pair<int, int>> &edges, int m)
{
    // code here
    vector<vector<int>>adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    vector<int> color(n, -1);
    return DFS(0, color, adj, n, m);
}

int main()
{
    int n = 4, m = 3;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};
    cout << graphColoring(n, edges, m); // true
}