#include<iostream>
using namespace std;

/*
    1 
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
*/

int main()
{
    int row, col;
    for(row=1; row<=5; row=row+1)
    {
        for(col=1; col<=row; col=col+1)
        {
            cout<<row<<" ";
        }
        cout<<endl;
    }
}