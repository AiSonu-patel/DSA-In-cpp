#include<iostream>
using namespace std;

/*
Enter the Number: 10
1 2 5 10 
*/

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    int i = 1;
    while(i<=n)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
        }
        i++;
    }
}