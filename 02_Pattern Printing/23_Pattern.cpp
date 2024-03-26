#include<iostream>
using namespace std;

/*
            1 
          1 2 1 
        1 2 3 2 1
      1 2 3 4 3 2 1
    1 2 3 4 5 4 3 2 1
*/

int main()
{
    int row, col;
    for(row=1; row<=5; row=row+1)
    {
        //print space --> (5-row) time
        for(col=1; col<=5-row; col=col+1)
        {
            cout<<"  ";
        }
        //print 1 to row no.
        for(col=1; col<=row; col=col+1)
        {
            cout<<col<<" ";
        }
        //print row-1 to 1 no.
        for(col=row-1; col>=1; col=col-1)
        {
            cout<<col<<" ";
        }
        cout<<endl;
    }
}