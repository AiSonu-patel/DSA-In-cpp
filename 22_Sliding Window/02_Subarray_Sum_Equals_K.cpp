#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n^3);
// Space Complexity = O(1);
int sumK1(vector<int> &arr, int k)
{
    int n = arr.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += arr[k];

            if (sum == k)
                total++;
        }
    }
    return total;
}

// Time Complexity = O(n^2);
// Space Complexity = O(1);
int sumK2(vector<int> &arr, int k)
{
    int n = arr.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                total++;
        }
    }
    return total;
}

// Time Complexity = O(n);
// Space Complexity = O(n);
int sumK3(vector<int> &arr, int k)
{
    int n = arr.size();
    int total = 0;
    int prefix = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        if (m.count(prefix-k))
        {
            total += m[prefix-k];
            m[prefix]++;
        }
        else
            m[prefix]++;
    }

    return total;
}

int main()
{
    // vector<int> arr = {1, 1, 1};
    // vector<int> arr = {1, 2, 3};
    // vector<int> arr = {3,4,5,3,-6,4,-2,12};
    vector<int> arr = {2,1,7,-4,2,1,3,4,-15,2,-3,6};
    int k = 6;
    // cout<<sumK1(arr, k);
    // cout<<sumK2(arr, k);
    cout << sumK3(arr, k); // 7
}