#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n^3);
// Space Complexity = O(1);
int subArrDivK1(vector<int>&arr, int k)
{
    int count = 0;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int sum = 0;
            for(int k=i; k<=j; k++)
            {
                sum +=arr[k];
            }
            if(sum%k==0)
            count++;
        }
    }
    return count;
}

// Time Complexity = O(n^2);
// Space Complexity = O(1);
int subArrDivK2(vector<int>&arr, int k)
{
    int n = arr.size();
    int count=0;
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum%k==0)
            count++;

        }
    }
    return count;
}

// Time Complexity = O(n);
// Space Complexity = O(n);
int subArrDivK3(vector<int>&arr, int k)
{
    int n = arr.size();
    int count = 0;
    int prefix = 0, pre;
    unordered_map<int, int>m;
    m[0]=1;
    for(int i=0; i<n; i++)
    {
        prefix+=arr[i];
        pre = prefix%k;
        if(pre<0)
        pre = k+pre;

        if(m.count(pre))
        {
            count += m[pre];
            m[pre]++;
        }
        else
        m[pre]=1;
    }
    return count;
}

int main()
{
    vector<int>arr = {3,5,6,3,9,4,6,9};
    // vector<int>arr = {2,3,-8,-3,11,4,8,6,9,4};
    // vector<int>arr = {4,5,0,-2,-3,1};
    // vector<int>arr = {5};
    int k = 7;
    // cout<<subArrDivK1(arr, k); // 5
    // cout<<subArrDivK2(arr, k); // 5
    cout<<subArrDivK3(arr, k); // 5
}