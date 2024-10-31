#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct(vector<int>&arr, int k)
{
    int n = arr.size();
    int total = 0;
    // Atleast(k) - Atleast(k+1)
    unordered_map<int, int>freq;
    int start=0, end=0, count=0;
    while(end<n)
    {
        freq[arr[end]]++;
        if(freq[arr[end]]==1)
        count++;

        while(count==k)
        {
            total += n-end;
            freq[arr[start]]--;

            if(freq[arr[start]]==0)
            count--;

            start++;
        }
        end++;
    }

    start=0, end=0, count=0;
    freq.clear();
    k++;

    while(end<n)
    {
        freq[arr[end]]++;
        if(freq[arr[end]]==1)
        count++;

        while(count==k)
        {
            total -= n-end;
            freq[arr[start]]--;

            if(freq[arr[start]]==0)
            count--;

            start++;
        }
        end++;
    }
    return total;
};

int main()
{
    // vector<int>arr = {1,2,1,2,3}; // k=2, out=7;
    vector<int>arr = {1,2,1,3,4}; // k=3, out=3;
    int k = 3;

    cout<<subarraysWithKDistinct(arr, k);
}