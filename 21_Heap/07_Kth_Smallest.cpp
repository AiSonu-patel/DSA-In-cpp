#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>&arr, int k)
{
    priority_queue<int>p; // max heap
    for(int i=0; i<k; i++)
    p.push(arr[i]);

    for(int i=k; i<arr.size(); i++)
    {
        if(arr[i]<p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

int main()
{
    vector<int>arr = {7,10,4,3,20,15};
    int k = 3;
    cout<<kthSmallest(arr, k); // 7
}