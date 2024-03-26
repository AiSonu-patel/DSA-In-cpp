#include<iostream>
using namespace std;

/*
    a 
    b b 
    c c c 
    d d d d 
    e e e e e
*/

int main()
{
    int row, col;
    for(row=1; row<=5; row=row+1)
    {
        char ch = 'a'+(row-1);
        for(col=1; col<=row; col=col+1)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}