#include<iostream>
using namespace std;

int totalway(int n)
{
    if(n<=1)
    return 1;

    return totalway(n-1)+totalway(n-2);
}

int main()
{
    int n; // 5
    cin>>n;

    cout<<totalway(n); // 8
}