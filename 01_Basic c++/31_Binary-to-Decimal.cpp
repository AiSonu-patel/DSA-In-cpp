#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the Binary Number: "; //101
    cin>>num;
    int rem, mul=1, ans=0;

    while(num>0)
    {
        rem = num%10;
        num = num/10;
        ans = rem*mul+ans;
        mul = mul*2;
    }
    cout<<ans; // 5
}