#include<iostream>
using namespace std;

/*
       * 
      * * 
     * * * 
    * * * * 
    * * * * 
     * * * 
      * * 
       * 
*/

int main()
{
    int row, col, n;
    cout<<"Enter the Number: "; // 4
    cin>>n;

    for(row=1; row<=n; row=row+1)
    {
        //print space
        for(col=1; col<=n-row; col=col+1)
        cout<<" ";
        //print * --> row time
        for(col=1; col<=row; col=col+1)
        cout<<"* ";

        cout<<endl;
    }

    for(row=n; row>=1; row=row-1)
    {
        //print space
        for(col=1; col<=n-row; col=col+1)
        cout<<" ";
        //print "* " --> row time
        for(col=1; col<=row; col=col+1)
        cout<<"* ";

        cout<<endl;
    }
}