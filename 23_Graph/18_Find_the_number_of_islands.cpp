#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BFS
// Time Complexity O(n*m)
// Space Complexity O(n*m)
int r,c;
int row[8] = {-1,-1,-1,1,1,1,0,0};
int col[8] = {-1,0,1,-1,0,1,-1,1};

bool valid(int i, int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
};

int numIslands(vector<vector<char>>grid)
{
    r = grid.size();
    c = grid[0].size();
    int count = 0;
    queue<pair<int,int>>q;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grid[i][j]=='1')
            {
                count++;
                q.push(make_pair(i,j));
                grid[i][j]='0';

                while(!q.empty())
                {
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();

                    for(int k=0; k<8; k++)
                    {
                        if(valid(new_i+row[k], new_j+col[k]) && grid[new_i+row[k]][new_j+col[k]]== '1')
                        {
                            grid[new_i+row[k]][new_j+col[k]]='0';
                            q.push(make_pair(new_i+row[k], new_j+col[k]));
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    // vector<vector<char>>grid = {{'0','1'},{'1','0'},{'1','1'},{'1','0'}}; // 1
    vector<vector<char>>grid = {{'0','1','1','1','0','0','0'},{'0','0','1','1','0','1','0'}}; // 2
    cout<<numIslands(grid);
}