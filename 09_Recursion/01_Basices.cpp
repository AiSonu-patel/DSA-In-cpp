#include<iostream>
using namespace std;

void fun(int n)
{
    if(n==0)
    {
        cout<<"Happy Birthday\n";
        return;
    }
    cout<<n<<" day left for birthday\n";

    fun(n-1);
}

int main()
{
    int day = 5;
    // Iterative approach
    // for(int i=5; i>0; i--)
    // {
    //     cout<<i<<" days left for birthday\n";
    // }
    // cout<<"Happy Birthday\n";

    fun(day);
}