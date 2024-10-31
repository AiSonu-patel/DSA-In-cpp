#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n^3);
// Space Complexity = O(1);
int sumZero1(vector<int>&arr)
{
    int total = 0;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int sum = 0;
            for(int k=i; k<=j; k++)
            {
                sum += arr[k];
            }
            if(sum==0)
            total++;
        }
    }
    return total;
};

// Time Complexity = O(n^2);
// Space Complexity = O(1);
int sumZero2(vector<int>&arr)
{
    int n = arr.size();
    int total = 0;
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
            if(sum==0)
            total++;
        }
    }
    return total;
}

// Time complexity = O(n);
// Time Complexity = O(n);
int sumZero3(vector<int>&arr)
{
    int n = arr.size();
    int total = 0;
    int prefix = 0;
    unordered_map<int, int>mp;
    mp[0]=1;
    for(int i=0; i<n; i++)
    {
        prefix+=arr[i];
        if(mp.count(prefix))
        {
            total+=mp[prefix];
            mp[prefix]++;
        }
        else
        mp[prefix]=1;
    }
    return total;
};

int main()
{
    vector<int>arr = {6,-1,-3,-2,2,4,6,-12,-2};
    // vector<int>arr = {6,4,-5,1,8,3,2,-10,-4,0,4,-9};
    // vector<int>arr = {0,0,5,5,0,0};

    // cout<<sumZero1(arr); // 5
    // cout<<sumZero2(arr); // 5
    cout<<sumZero3(arr); // 5
}