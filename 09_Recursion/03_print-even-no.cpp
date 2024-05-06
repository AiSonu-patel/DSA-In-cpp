#include<iostream>
using namespace std;

void printEven(int n)
{
    if(n==2)
    {
        cout<<2<<" ";
        return;
    }
    printEven(n-2);
    cout<<n<<endl;
}

void printEve(int num, int n)
{
    if(num>n)
    {
        return;
    }
    cout<<num<<endl;
    printEve(num+2, n);
}

int main()
{
    int n; // 8
    cin>>n;
    if(n%2==1)
    n--;

    printEven(n); // 2 4 6 8
    printEve(2, n); // 2 4 6 8
}