#include<iostream>
#include <math.h>
using namespace std;

// T.C -> O(2^n)
// S.C -> O(n)

void tohcol(int n, int sour, int help, int dest)
    {
        if(n==1)
        {
            cout<<"move disk "<<n<<" from rod "<<sour<<" to rod "<<dest<<endl;
            return;
        }
        
        tohcol(n-1, sour, dest, help);
        cout<<"move disk "<<n<<" from rod "<<sour<<" to rod "<<dest<<endl;
        tohcol(n-1, help, sour, dest);
    }
int main()
{
    int N=2;
    int sour=1;
    int help = 2;
    int dest = 3;
    tohcol(N,sour, help, dest);
    cout<<pow(2,N)-1;
}