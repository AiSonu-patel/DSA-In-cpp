#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O((V + E) log V)
// Auxiliary Space: O(V+E)

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int V = adj.size();
    vector<int> Dist(V, INT_MAX);
    vector<bool> Explored(V, 0);
    Dist[src] = 0;

    int count = V;
    while (count--)
    {
        int node = -1, value = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (!Explored[i] && value > Dist[i])
            {
                node = i;
                value = Dist[i];
            }
        }

        Explored[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;
            if (!Explored[neighbour] && (Dist[node] + weight < Dist[neighbour]))
                Dist[neighbour] = Dist[node] + weight;
        }
    }
    return Dist;
};

int main()
{
    vector<vector<pair<int, int>>>adj = {{{1,9}}, {{0,9}}};
    int src = 0;
    vector<int>ans = dijkstra(adj, src);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" "; // 0 9 
}