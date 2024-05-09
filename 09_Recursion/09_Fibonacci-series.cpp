#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if(n<=1)
    return n;
    
    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n; // 4
    cin>>n;
    if(n>1000)
    {
        cout<<"Not possibal fibonacci number";
        return 0;
    }
    cout<<fibonacci(n); // 3
}