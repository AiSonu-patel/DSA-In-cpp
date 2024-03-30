#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the binary number: "; // 1101
    cin>>num;
    int rem, mul=1, ans=0;
    
    // Binary --> Decimal
    while(num>0)
    {
        rem = num%10;
        num = num/10;
        ans = rem*mul+ans;
        mul = mul*2;
    }
    // cout<<ans; // 13

    // Decimal --> Octal
    int rem1, mul1=1, ans1=0;
    while(ans)
    {
        rem1 = ans%8;
        ans = ans/8;
        ans1 = rem1*mul1+ans1;
        mul1 = mul1*10;
    }
    cout<<ans1; // 15
}