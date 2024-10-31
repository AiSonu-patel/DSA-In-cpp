#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Length of Longest Subarray With at Most K Frequency
// Time Complexity = O(n)
// Space Complexity = O(n)
int maxSubarrayLength(vector<int>&arr, int k)
{
    int n = arr.size();
    int start = 0, end = 0, len = 0;
    unordered_map<int, int>m;
    while(end<n)
    {
        m[arr[end]]++;
        while(m[arr[end]]>k)
        {
            m[arr[start]]--;
            start++;
        }
        len = max(len, end-start+1);
        end++;
    }
    return len;
}

int main()
{
    vector<int>arr = {1,2,3,1,2,3,3,4,1,2}; // k=2, output=7;
    // vector<int>arr = {1,2,3,1,2,3,1,2}; // k=2, output=6;
    int k = 2;
    cout<<maxSubarrayLength(arr, k);
}