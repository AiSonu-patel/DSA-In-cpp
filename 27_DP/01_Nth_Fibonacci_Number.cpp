#include <iostream>
#include <vector>
using namespace std;

// Nth Fibonacci Number solve using recursion
// T.C -> O(2^n)
// T.C -> O(n)

int find(int n)
{
    if (n <= 1)
        return n;

    return find(n - 1) + find(n - 2);
};

// Nth Fibonacci Number solve using recursion + dp (top down approach)
// T.C -> O(n)
// S.C -> O(2n)

int solve(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

};

// Nth Fibonacci Number solve using dp (bottom up approach)
// T.C -> O(n)
// S.C -> O(n);

int solution(int n)
{
    vector<int>dp(n+1, -1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2; i<=n; i++)
    return dp[i] = dp[i-1]+dp[i-2];

    // return dp[n];
}

// Nth Fibonacci Number solve space optimization
// T.C -> O(n)
// S.C -> O(1)

int fibonacci(int n)
{
    if(n<=1)
    return n;

    int first = 0;
    int second = 1;
    int third;

    for(int i=2; i<=n; i++)
    {
        third = first+second;
        first = second;
        second = third;
    }

    return third;

};

int main()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    // cout<<solution(n); // 55
    cout<<fibonacci(n); // 55
}