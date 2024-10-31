#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Count Subarrays Where Max Element Appears at Least K Times
// Time Complexity O(n);
// Space Complexity O(1);
int countSubarrays(vector<int>&arr, int k)
{
    int n = arr.size();
    int start = 0, end = 0, ans = 0, count=0, maxEle=0;

    for(int i=0; i<n; i++)
    maxEle = max(maxEle, arr[i]);

    while(end<n)
    {
        if(arr[end]==maxEle)
        count++;

        while(count==k)
        {
            ans += n-end;
            if(arr[start]==maxEle)
            count--;

            start++;
        }
        end++;
    }
    return ans;
};

int main()
{
    vector<int>arr = {1,2,3,2,3,1,2,3,3,2}; // k=2, out=30
    int k = 2;
    cout<<countSubarrays(arr, k);
}