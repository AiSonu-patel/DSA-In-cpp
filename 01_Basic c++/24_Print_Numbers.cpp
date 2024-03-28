#include<iostream>
using namespace std;

/*
Enter the Number: 10
1
2
3
4
5
6
7
8
9
10
*/

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    int i = 1;
    while(i<=n)
    {
        cout<<i<<endl;
        i++;
    }
}