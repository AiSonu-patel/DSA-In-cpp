#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int>adj[], vector<vector<int>>&ans, vector<int>&disc, vector<int>&low, vector<bool>&visited, stack<int>&s, vector<bool>&InStack, int &timer)
{
    visited[node] = 1;
    InStack[node] = 1;
    s.push(node);
    disc[node] = low[node] = timer;

    for(int j=0; j<adj[node].size(); j++)
    {
        int neb = adj[node][j];
        if(!visited[neb])
        {
            timer++;
            DFS(neb, adj, ans, disc, low, visited, s, InStack, timer);
            low[node] = min(low[node], low[neb]);
        }
        else
        {
            if(InStack[neb])
            low[node] = min(low[node], disc[neb]);
        }
    }

    if(disc[node] == low[node])
    {
        vector<int>temp;
        while(!s.empty() && s.top()!=node)
        {
            temp.push_back(s.top());
            InStack[s.top()] = 0;
            s.pop();
        }

        temp.push_back(s.top());
        InStack[s.top()] = 0;
        s.pop();

        sort(temp.begin(), temp.end());
        ans.push_back(temp);
    }
};

vector<vector<int>> tarjans(int V, vector<int> adj[])
{
    //code here
    vector<vector<int>>ans;
    vector<int>disc(V);
    vector<int>low(V);
    vector<bool>visited(V, 0);
    stack<int>s;
    vector<bool>InStack(V, 0);
    int timer = 0;

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        DFS(i, adj, ans, disc, low, visited, s, InStack, timer);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int>adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);

    vector<vector<int>>ans = tarjans(5, adj);

    for(int i=0; i<ans.size(); i++)
    for(int j=0; j<ans[0].size(); j++)
    {
        cout<<ans[i][j]<<" "; // 0 1 2 3 4
    }

}