#include<iostream>
using namespace std;

void print(int n)
{
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    print(n-1);
    cout<<n<<endl;
}

void print1(int num, int n)
{
    if(num==n)
    {
        cout<<num<<endl;
        return;
    }
    cout<<num<<endl;
    print1(num+1, n);
}

int main()
{
    int n; // 4
    cin>>n;
    print(n); // 1 2 3 4
    print1(1, n); // 1 2 3 4
}