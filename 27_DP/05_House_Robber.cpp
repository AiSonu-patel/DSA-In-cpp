#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// recursion
// T.C -> O(2^n)
// S.C -> O(n)
int robber(int index, vector<int>&nums)
{
    if(index==0)
    return nums[0];

    if(index==1)
    return max(nums[0], nums[1]);

    return max(nums[index]+robber(index-2, nums), robber(index-1, nums));
};

// recursion + dp (topDownApproach)
// T.C -> O(n)
// S.C -> O(n)+O(n)
int topDownApproach(int index, vector<int>&nums, vector<int>&dp)
{
    if(index==0)
    return nums[0];

    if(index==1)
    return max(nums[0], nums[1]);

    if(dp[index] != -1)
    return dp[index];

    return dp[index] = max(nums[index]+topDownApproach(index-2, nums, dp), topDownApproach(index-1, nums, dp));
};

// bottomUpApproach
// T.C -> O(n)
// S.C -> O(n)
int bottomUpApproach(vector<int>&nums)
{
    int n = nums.size();
    vector<int>dp(n, -1);

    if(n==1)
    return nums[0];

    if(n==2)
    return max(nums[0], nums[1]);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n; i++)
    {
        dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
    }

    return dp[n-1];

};

// space Optimization
// T.C -> O(n)
// S.C -> (1)
int spaceOpt(vector<int>nums)
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

int rob(vector<int>& nums) 
{
    int n = nums.size();
    vector<int>dp(n, -1);

    // return robber(n-1, nums);

    // return topDownApproach(n-1, nums, dp);

    // return bottomUpApproach(nums);

    return spaceOpt(nums);
}

int main()
{
    vector<int>nums {1,2,3,1};
    cout<<rob(nums); // 4
}