#include<iostream>
#include <vector>
using namespace std;

// T.c -> O(n^2)
// S.C -> O(n)

int winner(vector<bool>&persion, int n, int index, int persion_left, int k)
{
    if(persion_left==1)
    {
        for(int i=0; i<n; i++)
        {
            if(persion[i]==0)
            return i;
        }
    }

    int kill = (k-1)%persion_left;
    while(kill--)
    {
        index = (index+1)%n;
        while(persion[index]==1)
        index = (index+1)%n;
    }

    persion[index] = 1;

    while(persion[index]==1)
    index = (index+1)%n;

    return winner(persion, n, index, persion_left-1, k);
}

// T.C -> O(n)
// S.C -> O(n)

int Winner(int n, int k)
{
    if(n==1)
    return 0;

    return (Winner(n-1, k)+k)%n;
}

int main()
{
    int n=16;
    // vector<bool>persion(n,0);
    // int kill = 3;
    // cout<<winner(persion, n, 0, n, kill); // 3

    cout<<Winner(n, 2)+1; // 3
}