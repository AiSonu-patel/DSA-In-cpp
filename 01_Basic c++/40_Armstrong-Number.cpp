#include<iostream>
#include <math.h>
#include<stdio.h>
using namespace std;

int countDigit(int num)
{
    int ans=0;
    while(num)
    {
        ans++;
        num/=10;
    }
    return ans;
}

bool Armstrong(int num, int digit)
{
    int n = num, rem, ans=0;
    while(n)
    {
        rem = n%10;
        n = n/10;
        ans +=pow(rem,digit);
    }

    if(ans==num)
    return 1;
    else
    return 0;
}

int main()
{
    int num;
    cin>>num;
    int digit = countDigit(num);
    cout<<Armstrong(num, digit)<<endl;
}