#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BFS
// Time Complexity O(n*m)
// Space Complexity O(n*m)

int r, c;
int row[4] = {0,-1,0,1};
int col[4] = {-1,0,1,0};

bool valid(int i, int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
};

int xShape(vector<vector<char>>grid)
{
    r = grid.size();
    c = grid[0].size();
    queue<pair<int,int>>q;
    int count = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grid[i][j]=='X')
            {
                count++;
                q.push(make_pair(i, j));
                grid[i][j]='0';

                while(!q.empty())
                {
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();

                    for(int k=0; k<4; k++)
                    {
                        if(valid(new_i+row[k], new_j+col[k]) && grid[new_i+row[k]][new_j+col[k]]=='X')
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
};

int main()
{
    vector<vector<char>>grid = {{'X','0','X'},{'0','X','0'},{'X','X','X'}}; // 3
    // vector<vector<char>>grid = {{'X','X'},{'X','X'}}; // 1

    cout<<xShape(grid);

}