#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
// Note: You can only move left, right, up and down, and only through cells that contain 1.

// BFS
// Time Complexity: O(n * m)
// Auxiliary Space: O(min(n,m))

int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j, int n, int m)
{
    return i>=0&&j>=0&&i<n&&j<m;
};

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
{
    // code here
    if(X==0 && Y==0)
    return 0;

    if(!A[0][0])
    return -1;

    queue<pair<int,int>>q;
    q.push({0,0});
    A[0][0] = 0;
    int step = 0;

    while(!q.empty())
    {
        int count = q.size();

        while(count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0; k<4; k++)
            {
                int new_i = i+row[k];
                int new_j = j+col[k];

                if(valid(new_i, new_j, N, M) && A[new_i][new_j])
                {
                    if(X==new_i && Y==new_j)
                    return step+1;

                    A[new_i][new_j]=0;
                    q.push({new_i, new_j});
                }
            }
        }
        step++;
    }
    return -1;
}

int main()
{
    vector<vector<int>>a = {{1,0,0,0},{1,1,0,1},{0,1,1,1}};
    int n = 3, m = 4, x = 2, y = 3;
    cout<<shortestDistance(n, m, a, x, y); // 5
}