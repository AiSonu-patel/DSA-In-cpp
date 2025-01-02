#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BFS
// Time Complexity O(n*m)
// space Complexity O(n*m)
int r,c;
int row[4] = {0,-1,0,1};
int col[4] = {-1,0,1,0};

bool valid(int i, int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
};

int orangesRotting(vector<vector<int>>mat)
{
    r = mat.size();
    c = mat[0].size();
    queue<pair<int,int>>q;
    int timer = -1;

    for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
    if(mat[i][j]==2)
    q.push(make_pair(i,j));

    while(!q.empty())
    {
        timer++;
        int curr_orange = q.size();
        while(curr_orange--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0; k<4; k++)
            {
                if(valid(i+row[k], j+col[k]) && mat[i+row[k]][j+col[k]]==1)
                {
                    mat[i+row[k]][j+col[k]]=2;
                    q.push(make_pair(i+row[k], j+col[k]));
                }
            }
        }
    }

    for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
    if(mat[i][j]==1)
    return -1;

    return timer==-1 ? 0 : timer;
}

int main()
{
    // vector<vector<int>>mat = {{0,1,2},{0,1,2},{2,1,1}}; // 1
    // vector<vector<int>>mat = {{2,2,0,1}}; // -1
    vector<vector<int>>mat = {{2,2,2},{0,2,0}}; // 0
    cout<<orangesRotting(mat);
}