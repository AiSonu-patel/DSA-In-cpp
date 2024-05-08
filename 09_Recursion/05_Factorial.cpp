#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==1 || n==0)
    return 1;

    return n*fact(n-1);
}

int main()
{
    int n; // 5
    cin>>n;
    if(n<0)
    {
        cout<<"Factorial is not possibal ";
        return 0;
    }

    cout<<fact(n); // 120

    // int fact=1;
    // for(int i=1; i<=n; i++)
    // {
    //     fact*=i;
    // }
    // cout<<fact; // 120
}