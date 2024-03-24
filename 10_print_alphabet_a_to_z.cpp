#include<iostream>
using namespace std;

int main()
{
    for(char ch = 'a'; ch <='z'; ch++)
    {
        cout<<ch<<" ";
    }
    cout<<endl;
    for(char ch = 'A'; ch <= 'Z'; ch++)
    {
        cout<<ch<<" ";
    }
    cout<<endl;
    for(int i=1; i<=10; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=10; i>=1; i--)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=1; i<=10; i++)
    {
        cout<<i*2<<" ";
    }
}