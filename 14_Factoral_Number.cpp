#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int ans = 1;
    for(int i=1; i<=n; i++)
    {
        ans = ans*i;
    }
    cout<<ans;
}