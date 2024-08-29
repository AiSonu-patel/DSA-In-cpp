#include<iostream>
using namespace std;

int step(int stair, int n)
{
    if(stair==n)
    return 1;

    if(stair>n)
    return 0;

    return step(stair+1, n)+step(stair+2, n);
};

int climbStairs(int n)
{
    return step(0, n);
};

int main()
{
    int n = 5;
    cout<<climbStairs(n); // 8
}