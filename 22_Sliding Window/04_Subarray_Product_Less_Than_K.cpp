#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time complexity = O(n^3);
// Space complexity O(1);
int subArraysDivByK1(vector<int> &arr, int k)
{
    int n = arr.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int product = 1;
            for (int k = i; k <= j; k++)
            {
                product *= arr[k];
            }
            if (product < k)
                total++;
        }
    }
    return total;
}

// Time complexity = O(n^2);
// Space complexity O(1);
int subArraysDivByK2(vector<int> &arr, int k)
{
    int n = arr.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= arr[j];
            if (product < k)
                total++;
        }
    }
    return total;
}

// Time complexity = O(n);
// Space complexity O(1);
int subArraysDivByK3(vector<int> &arr, int k)
{
    int n = arr.size();
    int total = 0;
    int product = 1;
    int start = 0, end = 0;
    while (end < n)
    {
        product *= arr[end];
        while (product >= k && start <= end)
        {
            product /= arr[start];
            start++;
        }
        total += 1 + (end - start);
        end++;
    }
    return total;
}

int main()
{
    // vector<int>arr = {2,5,10,8,100,1000,5,15}; // k=999, output = 15;
    vector<int> arr = {10, 5, 2, 6}; // k = 100, output = 8
    // vector<int>arr = {1,2,3}; // k=0, output = 0;
    int k = 100;
    // cout << subArraysDivByK1(arr, k);
    // cout<<subArraysDivByK2(arr, k);
    cout << subArraysDivByK3(arr, k);
}