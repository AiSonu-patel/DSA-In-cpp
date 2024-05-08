#include<iostream>
using namespace std;

int Power(int n, int p)
{
    if(p==0)
    return 1;
    
    if(p==1)
    return n;

    return n*Power(n, p-1);
}

int main()
{
    int number, power; // 2^5
    cin>>number>>power;

    cout<<Power(number, power); // 32
}