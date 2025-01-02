#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n+m)

vector<int> shortestPath(int V, int m, vector<vector<int>>& edges)
{
    // adjacency list create
    // neighbour, weight
    vector<pair<int, int>>adj[V+1];
    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Dijkstra Algorithm
    vector<bool>Explored(V+1, 0);
    vector<int>dist(V+1, INT_MAX);
    vector<int>parent(V+1, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    q.push({0, 1});
    dist[1]=0;

    while(!q.empty())
    {
        int node = q.top().second;
        q.pop();
        if(Explored[node])
        continue;

        Explored[node]=1;
        for(int j=0; j<adj[node].size(); j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;
            if(!Explored[neighbour] && dist[node]+weight<dist[neighbour])
            {
                dist[neighbour] = dist[node]+weight;
                q.push({dist[neighbour], neighbour});
                parent[neighbour] = node; // line added
            }
        }
    }

    vector<int>path;

    // I can't reach my destination
    if(parent[V]==-1)
    {
        path.push_back(-1);
        return path;
    }

    // I will reach my destination
    int dest = V;
    while(dest!=-1)
    {
        path.push_back(dest);
        dest = parent[dest];
    }

    path.push_back(dist[V]);
    reverse(path.begin(), path.end());

    return path;

};

int main()
{
    int n = 2;
    int m = 1;
    vector<vector<int>>edges = {{1, 2, 2}};
    vector<int>ans = shortestPath(n, m, edges);
    int sum = 0;
    for(int i=0; i<ans.size(); i++)
    sum+=ans[i];

    cout<<sum; // 5
}