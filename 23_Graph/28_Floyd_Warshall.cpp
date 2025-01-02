#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(n^3)
// Space Complexity O(1)

void shortestDistance(vector<vector<int>>& mat)
{
    int n = mat.size();
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    if(mat[i][j]==-1)
    mat[i][j]=INT_MAX;

    // Floyd Warshall algorithm
    for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    {
        if(mat[i][k]==INT_MAX || mat[k][j]==INT_MAX)
        continue;

        mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
    }

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    if(mat[i][j]==INT_MAX)
    mat[i][j]=-1;
}

int main()
{
    vector<vector<int>>mat = {{0,1,43},{1,0,6},{-1,-1,0}};
    shortestDistance(mat);
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[0].size(); j++)
        cout<<mat[i][j]<<" ";

        cout<<endl;
    }

    // ans -->
    
    // 0 1 7 
    // 1 0 6
    // -1 -1 0
}