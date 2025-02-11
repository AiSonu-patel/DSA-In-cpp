#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int robbery(vector<int>&nums)
{
    int n = nums.size();

    if(n==1)
    return nums[0];

    if(n==2)
    return max(nums[0], nums[1]);

    int prev2 = nums[0], prev = max(nums[0], nums[1]), curr;

    for(int i=2; i<n; i++)
    {
        curr = max(nums[i]+prev2, prev);
        prev2 = prev;
        prev = curr;
    }

    return curr;
};

int rob(vector<int>&nums)
{
    int n = nums.size();

    if(n==1)
    return nums[0];

    if(n==2)
    return max(nums[0], nums[1]);

    vector<int>arr1(n-1);
    vector<int>arr2(n-1);

    for(int i=0; i<n-1; i++)
    arr1[i] = nums[i];

    for(int i=1; i<n; i++)
    arr2[i-1] = nums[i];

    int curr1 = robbery(arr1);
    int curr2 = robbery(arr2);

    return max(curr1, curr2);
};

int rob2(vector<int>&nums)
{
    int n = nums.size();

    if(n==1)
    return nums[0];

    if(n==2)
    return max(nums[0], nums[1]);

    int prev2 = nums[0], prev = max(nums[0], nums[1]), curr1;
    curr1 = prev;

    for(int i=2; i<n-1; i++)
    {
        curr1 = max(nums[i]+prev2, prev);
        prev2 = prev;
        prev = curr1;
    }

    int curr2;
    prev2 = nums[1], prev = max(nums[1], nums[2]);
    curr2 = prev;

    for(int i=3; i<n; i++)
    {
        curr2 = max(nums[i]+prev2, prev);
        prev2 = prev;
        prev = curr2;
    }

    return max(curr1, curr2);
};


int main()
{
    vector<int>nums = {2,3,2};

    // cout<<rob(nums); // 3

    cout<<rob2(nums); // 3

}