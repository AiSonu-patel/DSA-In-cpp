#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Adjacency List
// Directed Unweighted Graph
// Time complexity O(v+E)
// Space complexity O(v+E)

int main()
{
    int vertex, edges;
    cin>>vertex>>edges;

    vector<int>AdjList[vertex];

    int u, v;
    for(int i=0; i<edges; i++)
    {
        cin>>u>>v;
        AdjList[u].push_back(v);
    }

    // print
    for(int i=0; i<vertex; i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<AdjList[i].size(); j++)
        cout<<AdjList[i][j]<<" ";

        cout<<endl;
    }
}