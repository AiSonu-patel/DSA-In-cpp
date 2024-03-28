#include<iostream>
using namespace std;

/*
1 2 3 4 5 6 7 8 9 10 
*/

int main()
{
    int n = 10;
    int sum = 0;
    int i = 1;
    do
    {
        sum += i;
        i++;
    }
    while(i<=n);

    cout<<sum; // 55
}