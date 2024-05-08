#include<iostream>
using namespace std;

int sum(int n)
{
    if(n==1)
    return 1;

    return n+sum(n-1);
}

int main()
{
    int n; // 5
    cin>>n;

    cout<<sum(n); // 15

    // int sum=0;
    // for(int i=1; i<=n; i++)
    // {
    //     sum+=i;
    // }
    // cout<<sum; // 15
}