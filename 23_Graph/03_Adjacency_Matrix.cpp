#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Adjacency Matrix
// Directed Unweighted Graph
// Time Complexity O(v^2)
// Space Complexity O(v^2)

int main()
{
    int vertex, edge;
    cin>>vertex>>edge;

    vector<vector<bool>>AdjMat(vertex, vector<bool>(vertex, 0));

    int u,v;
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        AdjMat[u][v]=1;
    }

    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        cout<<AdjMat[i][j]<<" ";

        cout<<endl;
    }
}