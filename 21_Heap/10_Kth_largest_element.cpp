#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int kthSmallest(int N, vector<vector<int>>&mat,  int K)
{
    int start = mat[0][0];
    int end = mat[N-1][N-1];
    int ans = 0;
    int count = 1;

    if(N==1)
    {
        ans = mat[0][0];
    }
    else
    {
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    if(mat[i][j]<=mid)
                    {
                        count++;
                    }
                }
            }
            if(count>=K)
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
            count = 0;
        }
    }
    return ans;
};

int main()
{
    int N = 4;
    vector<vector<int>>mat = {{16,28,60,64},{22,41,63,91},{27,50,87,93},{36,78,87,94}};
    int K = 3;

    cout<<kthSmallest(N, mat, K); // 27
};