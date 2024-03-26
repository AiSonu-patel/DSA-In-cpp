#include<iostream>
using namespace std;

/*
    * * * * * * * * * 
      * * * * * * *
        * * * * *
          * * *
            *
*/

int main()
{
    int row, col;
    for(row=5; row>=1; row=row-1)
    {
        //print space --> (5-row) time
        for(col=1; col<=5-row; col=col+1)
        {
            cout<<"  ";
        }
        //print "*" --> (2*row-1) time
        for(col=1; col<=2*row-1; col=col+1)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}