#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the Number: ";
    cin>>num;
    int rem, mul=1, ans=0;

    while(num)
    {
        rem = num%8;
        num = num/8;
        ans = rem*mul+ans;
        mul = mul*10;
    }
    cout<<ans;
}