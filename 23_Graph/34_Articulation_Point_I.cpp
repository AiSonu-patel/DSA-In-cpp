#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(V+E)
// Time Complexity O(V)

void DFS(int node, int parent, vector<int>adj[], vector<bool>&visited, vector<int>&disc, vector<int>&low, vector<bool>&artPoint, int &timer)
{
    visited[node] = 1;
    disc[node] = low[node] = timer;
    int child = 0;

    for(int j=0; j<adj[node].size(); j++)
    {
        int neb = adj[node][j];
        if(neb==parent)
        continue;
        else if(visited[neb])
        {
            low[node] = min(low[node], disc[neb]);
        }
        else
        {
            child++;
            timer++;
            DFS(neb, node, adj, visited, disc, low, artPoint, timer);
            if(disc[node]<=low[neb] && parent != -1)
            {
                artPoint[node]=1;
            }
            
            low[node] = min(low[node], low[neb]);
        }
    }
    if(child > 1 && parent == -1)
    {
        artPoint[node] = 1;
    }
};

vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<bool>artPoint(V, 0);
    vector<int>disc(V);
    vector<int>low(V);
    vector<bool>visited(V,0);
    int timer = 0;
    DFS(0, -1, adj, visited, disc, low, artPoint, timer);

    vector<int>ans;
    for(int i=0; i<V; i++)
    {
        if(artPoint[i])
        ans.push_back(i);
    }

    if(ans.size()==0)
    ans.push_back(-1);

    return ans;
}

int main()
{
    vector<int> adj[5];
    adj[0] = {1};
    adj[1] = {0, 4};
    adj[2] = {4, 3};
    adj[3] = {2, 4};
    adj[4] = {1 ,2, 3};
    

    vector<int>ans = articulationPoints(5, adj);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" "; // 1 4
}