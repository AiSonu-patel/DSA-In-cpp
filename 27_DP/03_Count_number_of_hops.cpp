#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// recursion 
// Time Complexity (2^n)
// Space Complexity O(3n) -> O(n)
int countWays(int i, int n)
{
    if(i==n)
    return 1;

    if(i>n)
    return 0;

    return countWays(i+1, n)+countWays(i+2, n)+countWays(i+3, n);
};

int countWays2(int n)
{
    if(n==0)
    return 1;

    if(n<0)
    return 0;

    return countWays2(n-1)+countWays2(n-2)+countWays2(n-3);
};

// using recursion + dp (top down approach)
// T.C -> O(n)
// S.C -> O(3n)+O(n) -> O(n)

int topDownApproach(int i, int n, vector<int>&dp)
{
    if(i==n)
    return 1;

    if(i>n)
    return 0;

    if(dp[i] != -1)
    return dp[i];

    return dp[i] = topDownApproach(i+1, n, dp)+topDownApproach(i+2, n, dp)+topDownApproach(i+3, n, dp);
};

int topDownApproach2(int n, vector<int>&dp)
{
    if(n==2)
    return 2;

    if(n<=1)
    return 1;

    if(dp[n] != -1)
    return dp[n];

    return dp[n] = topDownApproach2(n-1, dp)+topDownApproach2(n-2, dp)+topDownApproach2(n-3, dp);
};

// using solve bottomUpApproach
// T.C -> O(n)
// S.C -> O(n+3) -> O(n)

int bottomUpApproach(int n)
{
    vector<int>dp(n+3, -1);
    dp[n] = 1;
    dp[n+1] = 0;
    dp[n+2] = 0;

    for(int i=n-1; i>=0; i--)
    dp[i] = dp[i+1]+dp[i+2]+dp[i+3];

    return dp[0];
};

int bottomUpApproach2(int n)
{
    vector<int>dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++)
    dp[i] = dp[i-1]+dp[i-2]+dp[i-3];

    return dp[n];
};

// Space Optimization 
// T.C -> O(n)
// S.C -> O(1)
int spaceOpt(int n)
{
    int next3 = 0;
    int next2 = 0;
    int next1 = 1;
    int curr = 1;

    for(int i=n-1; i>=0; i--)
    {
        curr = next1+next2+next3;
        next3 = next2;
        next2 = next1;
        next1 = curr;
    }

    return curr;
};

int spaceOpt2(int n)
{
    int prev1 = 2;
    int prev2 = 1;
    int prev3 = 1;
    int curr = 1;

    for(int i=3; i<=n; i++)
    {
        curr = prev1+prev2+prev3;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n = 4;

    // cout<<countWays(0, n); // 7

    // cout<<countWays2(n); // 7

    // vector<int>dp(n+3, -1);
    // topDownApproach(0, n, dp);
    // cout<<dp[0]; // 7

    // vector<int>dp(n+1, -1);
    // topDownApproach2(n, dp);
    // cout<<dp[n]; // 7

    // cout<<bottomUpApproach(n); // 7

    // cout<<bottomUpApproach2(n); // 7

    // cout<<spaceOpt(n); // 7

    cout<<spaceOpt2(n); // 7
}