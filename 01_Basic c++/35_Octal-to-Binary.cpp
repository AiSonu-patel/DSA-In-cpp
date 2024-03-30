#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the Octal Number: "; // 15
    cin>>num;
    int rem, mul=1, ans=0;

    // Octal --> Decimal;
    while(num>0)
    {
        rem = num%10;
        num = num/10;
        ans = rem*mul+ans;
        mul = mul*8;
    }
    // cout<<ans; // 13

    int ans1=0, mul1=1, rem1;
    // Decimal --> Binary
    while(ans>0)
    {
        rem1 = ans%2;
        ans = ans/2;
        ans1 = rem1*mul1+ans1;
        mul1 = mul1*10;
    }
    cout<<ans1; // 1101
}