#include<iostream>
using namespace std;

/*
    1 2 3 4 5 
    1 2 3 4 5 
    1 2 3 4 5 
    1 2 3 4 5 
    1 2 3 4 5
*/

int main()
{
    int row, col;
    for(row=1; row<=5; row=row+1)
    {
        for(col=1; col<=5; col=col+1)
        {
            cout<<col<<" ";
        }
        cout<<endl;
    }
}