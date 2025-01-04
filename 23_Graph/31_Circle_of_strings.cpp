#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

void DFS(int node, vector<int>adj[], vector<bool>&visited)
{
    visited[node] = 1;
    for(int j=0; j<adj[node].size(); j++)
    {
        if(!visited[adj[node][j]])
        DFS(adj[node][j], adj, visited);
    }
}

int isCircle(vector<string> &arr)
{
    // code here
    int N = arr.size();
    // edges create 
    // Adjacency list
    // a-z
    // a-0, b-1, c-2, d-3, ... z-25
    vector<int>adj[26];
    vector<int>OutDeg(26, 0);
    vector<int>InDeg(26,0);
    for(int i=0; i<N; i++)
    {
        string temp = arr[i];
        int u = temp[0]-'a';
        int v = temp[temp.size()-1]-'a';
        adj[u].push_back(v);
        OutDeg[u]++;
        InDeg[v]++;
    }

    // Eluerian Circuit
    // Find InDegree OutDegree

    for(int i=0; i<26; i++)
    {
        if(InDeg[i]!=OutDeg[i])
        return 0;
    }

    // all the edges are part of one component
    vector<bool>visited(26,0);
    int node = arr[0][0]-'a';
    DFS(node, adj, visited);

    for(int i=0; i<26; i++)
    {
        if(InDeg[i]&&!visited[i])
        return 0;
    }
    return 1;
}

int main()
{
    // vector<string>s = {"abc","bcd","cdf"}; // 0
    // vector<string>s = {"for","geek","rig","kaf"}; // 1
    vector<string>s = {"ab","bc","cd","da"}; // 1
    cout<<isCircle(s);
}