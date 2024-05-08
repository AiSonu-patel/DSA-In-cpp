#include<iostream>
using namespace std;

int sqsum(int n)
{
    if(n==0)
    return 1;

    if(n==1)
    return n;

    return n*n+sqsum(n-1);
}

int main()
{
    int n; // 4
    cin>>n;
    if(n<0)
    {
        cout<<"sum of square is not possibal";
        return 0;
    }
    cout<<sqsum(n); // 30
}