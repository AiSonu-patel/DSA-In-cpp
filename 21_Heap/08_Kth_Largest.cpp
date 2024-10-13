#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>&arr, int k)
{
    priority_queue<int, vector<int>, greater<int>>p; // min heap
    for(int i=0; i<k; i++)
    p.push(arr[i]);

    for(int i=k; i<arr.size(); i++)
    {
        if(arr[i]>p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
};

int main()
{
    vector<int>arr = {3,2,1,5,6,4};
    int k = 2;

    cout<<findKthLargest(arr, k); // 5
}