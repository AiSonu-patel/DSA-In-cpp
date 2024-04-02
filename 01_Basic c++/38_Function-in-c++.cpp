#include<iostream>
using namespace std;

bool Prime(int n) // Function declare
{
    // function define
    if(n<2)
    return 0;
    
    for(int i=2; i<=n-1; i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}

int Fact(int n) // function declare
{
    // function define
    int ans = 1;
    for(int i=1; i<=n; i++)
    {
        ans *=i;
    }
    return ans;
}

int main()
{
    int a, b; // 4, 8
    cout<<"Enter the Number: ";
    cin>>a>>b;

    // pass by value :-
    cout<<Prime(a)<<endl; // 0
    cout<<Fact(a)<<endl; // 24
    cout<<Prime(b)<<endl; // 0
    cout<<Fact(b)<<endl; // 40320
    cout<<Prime(b-a)<<endl; // 0
    cout<<Fact(b-a)<<endl; // 24
}