#include<iostream>
using namespace std;

/*
    1 4 9 16 25 
    1 4 9 16 25 
    1 4 9 16 25 
    1 4 9 16 25 
    1 4 9 16 25 
*/

int main()
{
    int row, col;
    for(row=1; row<=5; row=row+1)
    {
        for(col=1; col<=5; col=col+1)
        {
            cout<<col*col<<" ";
        }
        cout<<endl;
    }
}