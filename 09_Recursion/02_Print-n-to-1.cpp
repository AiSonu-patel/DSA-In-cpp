#include<iostream>
using namespace std;

void print(int n)
{
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    cout<<n<<endl;
    print(n-1);
}

int main()
{
    int n;
    cin>>n;

    print(n); // 5 4 3 2 1
}