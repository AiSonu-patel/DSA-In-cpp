#include<iostream>
using namespace std;

void gcd(int a, int b)
{
    if(b==0)
    {
        cout<<a;
        return;
    }

    gcd(b, a%b);
}

int main()
{
    int a=18, b=48;
    gcd(a,b); // 6
}