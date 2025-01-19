#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies+N);
    int min_amount = 0, max_amount = 0;
    int i=0, j=N-1;
    while(i<=j)
    {
        min_amount+=candies[i];
        i++;
        j-=K;
    }

    i=0, j=N-1;
    while(i<=j)
    {
        max_amount+=candies[j];
        j--;
        i+=K;
    }

    vector<int>ans;
    ans.push_back(min_amount);
    ans.push_back(max_amount);
    return ans;
};

int main()
{
    int N = 4;
    int K = 2;
    int candies[] = {3,2,1,4};
    vector<int>ans = candyStore(candies, N, K);
    cout<<ans[0]<<" "; // min_amount 3
    cout<<ans[1]<<" "; // max_amount 7
}