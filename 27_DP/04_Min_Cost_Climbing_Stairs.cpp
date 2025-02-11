#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// recursion 
// T.C -> O(2^n)
// S.C -> O(n)
int ways(vector<int>&cost, int n)
{
    if(n<=1)
    return 0;

    return min(cost[n-1]+ways(cost, n-1), cost[n-2]+ways(cost, n-2));
};

// using recursion + dp (topDownApproach)
// T.C -> O(n)
// S.C -> O(n)+O(n) -> O(n)
int topDownApproach(vector<int>&cost, int n, vector<int>&dp)
{
    if(n<=1)
    return 0;

    if(dp[n] != -1)
    return dp[n];

    return dp[n] =  min(cost[n-1]+topDownApproach(cost, n-1, dp), cost[n-2]+topDownApproach(cost, n-2, dp));
};

// bottomUpApproach
// T.C -> O(n)
// S.C -> O(n)
int bottomUpApproach(vector<int>&cost, int n)
{
    vector<int>dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2; i<=n; i++)
    {
        dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
    }

    return dp[n];
};

// Space Optimization
// T.C -> O(n)
// S.C -> O(1)
int spaceOpt(vector<int>&cost, int n)
{
    int prev1 = 0, prev = 0, curr;
    for(int i=2; i<=n; i++)
    {
        curr = min(cost[i-1]+prev, cost[i-2]+prev1);
        prev1 = prev;
        prev = curr;
    }

    return curr;
}

int main()
{
    vector<int>cost {10,15,20};
    int n = cost.size();

    // cout<<ways(cost, n); // 15

    // vector<int>dp(n+1, -1);
    // cout<<topDownApproach(cost, n, dp); // 15

    // cout<<bottomUpApproach(cost, n); // 15

    cout<<spaceOpt(cost, n); // 15
}