#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr, int B)
{
    priority_queue<int>p;
    int sum = 0;
    for(int i=0; i<arr.size(); i++)
    p.push(arr[i]);

    while(B)
    {
        sum += p.top();

        if(p.top()-1)
        p.push(p.top()-1);

        p.pop();
        B--;
    }
    return sum;
}

int main()
{
    vector<int>arr = {2,3};
    int B = 3;
    cout<<solve(arr, B); // 7
}