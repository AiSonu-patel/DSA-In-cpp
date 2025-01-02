#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BFS
// Time Complexity O(n*m)
// Space Complexity O(n*m)

int r,c;
int row[4] = {0,-1,0,1};
int col[4] = {-1,0,1,0};

bool valid(int i, int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
};

void fill(vector<vector<char>>&mat)
{
    r = mat.size();
    c = mat[0].size();
    queue<pair<int,int>>q;

    // first row
    for(int j=0; j<c; j++)
    {
        if(mat[0][j]=='O')
        {
            q.push(make_pair(0, j));
            mat[0][j]='T';
        }
    }
    // first col
    for(int i=1; i<r; i++)
    {
        if(mat[i][0]=='O')
        {
            q.push(make_pair(i, 0));
            mat[i][0]='T';
        }
    }
    // last row
    for(int j=1; j<c; j++)
    {
        if(mat[r-1][j]=='O')
        {
            q.push(make_pair(r-1, j));
            mat[r-1][j]='T';
        }
    }
    // last col
    for(int i=1; i<r-1; i++)
    {
        if(mat[i][c-1]=='O')
        {
            q.push(make_pair(i, c-1));
            mat[i][c-1]='T';
        }
    }

    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(int k=0; k<4; k++)
        {
            if(valid(i+row[k], j+col[k]) && mat[i+row[k]][j+col[k]]=='O')
            {
                mat[i+row[k]][j+col[k]] = 'T';
                q.push(make_pair(i+row[k], j+col[k]));
            }
        }
    }

    for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
    {
        if(mat[i][j]=='O')
        {
            mat[i][j]='X';
        }
        else if(mat[i][j]=='T')
        {
            mat[i][j]='O';
        }
    }

}

int main()
{
    vector<vector<char>>mat = {{'X','X','X','X'},{'X','O','X','X'},{'X','O','O','X'},{'X','O','X','X'},{'X','X','O','O'}};
    fill(mat);
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[0].size(); j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}