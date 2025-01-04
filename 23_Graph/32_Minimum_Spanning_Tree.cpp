#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // priority queue
    // wait, node, parent
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> isMST(V, 0);
    vector<int> parent(V);
    pq.push({0, {0, -1}});
    int cost = 0;
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();

        if (!isMST[node])
        {
            isMST[node] = 1;
            cost += wt;
            parent[node] = par;

            for (int j = 0; j < adj[node].size(); j++)
            {
                if (!isMST[adj[node][j][0]])
                    pq.push({adj[node][j][1], {adj[node][j][0], node}});
            }
        }
    }
    return cost;
}

int main()
{
    vector<vector<int>>adj[1];
    adj[0].push_back({1, 5});

    cout << spanningTree(2, adj); // 5
}