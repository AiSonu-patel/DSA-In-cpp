#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// recursion 
// Time Complexity (2^n)
// Space Complexity (n)
int count(int i, int n)
{
    if(i==n)
    return 1;

    if(i>n)
    return 0;

    return count(i+1, n)+count(i+2, n);
}

int count2(int n)
{
    if(n<=1)
    return 1;

    return count2(n-1)+count2(n-2);
}

// Climbing Stairs solve using recursion + dp (top down approach)
// T.C -> O(n)
// S.C -> O(2n) -> O(n)

int topDownApproach(int i, int n, vector<int>&dp)
{
    if(i==n)
    return 1;

    if(i>n)
    return 0;

    if(dp[i]!=-1)
    return dp[i];

    return dp[i] = topDownApproach(i+1, n, dp)+topDownApproach(i+2, n, dp);
};

int topDownApproach2(int n, vector<int>&dp)
{
    if(n<=1)
    return 1;

    if(dp[n] != -1)
    return dp[n];

    return dp[n] = topDownApproach2(n-1, dp)+topDownApproach2(n-2, dp);
};

// Nth Fibonacci Number solve using dp (bottom up approach)
// T.C -> O(n)
// S.C -> O(n);

int bottomUpApproach(int n)
{
    vector<int>dp(n+1, -1);
    dp[n+1] = 0;
    dp[n] = 1;
    
    for(int i=n-1; i>=0; i--)
    {
        dp[i] = dp[i+1]+dp[i+2];
    }

    return dp[0];
}

int bottomUpApproach2(int n)
{
    vector<int>dp(n+1, -1);
    dp[1] = 1;
    dp[0] = 1;

    for(int i=2; i<=n; i++)
    dp[i] = dp[i-1]+dp[i-2];

    return dp[n];
}

// Nth Fibonacci Number solve space optimization
// T.C -> O(n)
// S.C -> O(1)

int spaceOptimization(int n)
{
    int next2 = 0;
    int next = 1;
    int curr;

    for(int i=n-1; i>=0; i--)
    {
        curr = next2+next;
        next2 = next;
        next = curr;
    }

    return curr;

}

int spaceOptimization2(int n)
{
    int second = 1, first = 1, curr = 1;

    for(int i=2; i<n+1; i++)
    {
        curr = second+first;
        first = second;
        second = curr;
    }

    return curr;
}

int climbStairs(int n)
{
    return spaceOptimization2(n);
};

int main()
{
    int n = 5;
    cout<<climbStairs(n); // 8
}