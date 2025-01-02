#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Connect Graph
// Breadth-First Search (BFS) Traversal
// Time Complexity O(v+e)
// Space Complexity O(v)

vector<int> bfsOfGraph(vector<vector<int>>&adj)
{
    int v = adj.size();
    vector<int>ans;
    queue<int>q;
    vector<bool>visited(v,0);
    q.push(0);
    visited[0]=1;
    int node;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        ans.push_back(node);

        for(int j=0; j<adj[node].size(); j++)
        {
            if(!visited[adj[node][j]])
            {
                visited[adj[node][j]]=1;
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>>adj = {{2,3,1},{0},{0,4},{0},{2}};
    vector<int>ans = bfsOfGraph(adj);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" "; // 0 2 3 1 4
    }
}