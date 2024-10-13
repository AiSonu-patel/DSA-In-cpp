#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Sum of elements between k1'th and k2'th smallest elements

long long sumBetweenTwoKth(vector<long long>&arr, long long K1, long long K2)
{
    priority_queue<int>p1;
    priority_queue<int>p2;

    for(long long i=0; i<K1; i++)
    p1.push(arr[i]);

    for(long long i=0; i<K2-1; i++)
    p2.push(arr[i]);

    for(long long i=K1; i<arr.size(); i++)
    {
        if(arr[i]<p1.top())
        {
            p1.pop();
            p1.push(arr[i]);
        }
    }

    for(long long i=K2-1; i<arr.size(); i++)
    {
        if(arr[i]<p2.top())
        {
            p2.pop();
            p2.push(arr[i]);
        }
    }

    long long sum1=0, sum2=0;
    while(!p1.empty())
    {
        sum1+=p1.top();
        p1.pop();
    }

    while(!p2.empty())
    {
        sum2+=p2.top();
        p2.pop();
    }

    return sum2-sum1;
};

int main()
{
    vector<long long>arr = {20, 8, 22, 4, 12, 10, 14};
    long long K1 = 3, K2 = 6;
    cout<<sumBetweenTwoKth(arr, K1, K2); // 26
}