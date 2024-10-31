#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n^2)
// Space Complexity = O(1)
int minSubArrayLen1(vector<int>&arr, int k)
{
    int n = arr.size();
    int ans = INT_MAX;
    for(int i=0; i<n; i++)
    {
        int prefix = 0;
        for(int j=i; j<n; j++)
        {
            prefix += arr[j];

            if(prefix>=k)
            {
                int size = (j-i)+1;
                ans = min(ans, size);
            }
        }
    }
    if(ans==INT_MAX)
    return 0;

    return ans;
};

// Time Complexity = O(n);
// Space Complexity = O(1)
int minSubArrayLen2(vector<int>&arr, int k)
{
    int n = arr.size();
    int ans = INT_MAX;
    int start = 0, end = 0, sum=0;
    while(end<n)
    {
        sum += arr[end];
        while(sum>=k && start<=end)
        {
            int size = 1+(end-start);
            ans = min(ans, size);
            sum -=arr[start];
            start++;
        }
        end++;
    }
    if(ans == INT_MAX)
    return 0;
    
    return ans;
}

int main()
{
    // vector<int>arr = {2,3,1,2,4,3}; // k=7, out=2
    // vector<int>arr = {1,4,4}; // k=4, out=1
    vector<int>arr = {1,1,1,1,1,1,1,1}; // k=11, out=0
    int target = 11;
    // cout<<minSubArrayLen1(arr, target);
    cout<<minSubArrayLen2(arr, target);
}