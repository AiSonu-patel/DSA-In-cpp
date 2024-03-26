#include<iostream>
using namespace std;

/*
            A 
          A B
        A B C
      A B C D
    A B C D E
*/

int main()
{
    int row, col;
    for(row=1; row<=5; row=row+1)
    {
        for(col=1; col<=5-row; col=col+1)
        {
            cout<<"  ";
        }
        for(char ch='A'; ch<='A'+row-1; ch=ch+1)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }

    // for(row=1; row<=5; row=row+1)
    // {
    //     for(col=1; col<=5-row; col=col+1)
    //     {
    //         cout<<"  ";
    //     }
    //     for(col=1; col<=row; col=col+1)
    //     {
    //         char ch = 'A'+(col-1);
    //         cout<<ch<<" ";
    //     }
    //     cout<<endl;
    // }
}