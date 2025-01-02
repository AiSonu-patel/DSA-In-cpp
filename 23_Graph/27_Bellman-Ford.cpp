#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V * E)
// Auxiliary Space: O(V)

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src)
{
    vector<int>dist(V, 1e8);
    dist[src]=0;
    int e = edges.size();
    for(int i=0; i<V-1; i++)
    {
        bool flag = 0;
        for(int j=0; j<e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u]==1e8)
            continue;

            if(dist[u]+w<dist[v])
            {
                flag = 1;
                dist[v] = dist[u]+w;
            }
        }

        if(!flag)
        return dist;
    }

    for(int j=0; j<e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u]==1e8)
        continue;

        if(dist[u]+w<dist[v])
        {
            vector<int>ans;
            ans.push_back(-1);
            return ans;
        }
    }

    return dist;
};

int main()
{
    int src = 2;
    vector<vector<int>>edges = {{0,1,5}, {1,0,3}, {1,2,-1},{2,0,1}};
    int V = 3;
    vector<int>ans = bellmanFord(V, edges, src);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";  // 1 6 0 
}