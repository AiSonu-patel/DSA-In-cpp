#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum cost of connecting the ropes.
long long minCost(vector<long long> &arr)
{
    // Your code here
    long long n = arr.size();
    priority_queue<long long, vector<long long>, greater<long long>> p;

    for (long long i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }

    long long cost = 0;

    while (p.size() > 1)
    {
        long long rope = p.top();
        p.pop();
        rope += p.top();
        p.pop();
        cost += rope;
        p.push(rope);
    }

    return cost;
}

int main()
{
    vector<long long> arr = {4, 3, 2, 6};
    cout<<minCost(arr); // 29
}
