#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int assignMiceHoles(int N , int M[] , int H[])
{
    sort(M, M+N);
    sort(H, H+N);
    int ans = INT_MIN;

    for(int i=0; i<N; i++)
    ans = max(ans, abs(M[i]-H[i]));

    return ans;
};

int main()
{
    int N = 3;
    int M[] = {4, -4, 2};
    int H[] = {4, 0, 5};

    cout<<assignMiceHoles(N, M, H); // 4
}