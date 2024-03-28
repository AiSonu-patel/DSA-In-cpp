#include<iostream>
using namespace std;

/*
Enter the Number: 10
3 4 6 7 8 9  
*/

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    int i = 1;
    while(i<=n)
    {
        if(n%i!=0)
        {
            cout<<i<<" ";
        }
        i++;
    }
}