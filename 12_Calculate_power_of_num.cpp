#include<iostream>
using namespace std;

int main()
{
    int num, pow;
    cout<<"Enter the Number: ";
    cin>>num;
    cout<<"Enter the power of Number: ";
    cin>>pow;
    int ans = num;

    for(int i=1; i<pow; i++)
    {
        ans = ans*num;
        cout<<ans;
    }
}