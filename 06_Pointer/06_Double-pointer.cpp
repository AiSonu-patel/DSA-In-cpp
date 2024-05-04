#include<iostream>
using namespace std;

void fun(int *p)
{
    *p = *p+5;
}

int main()
{
    int n = 10;
    int *p = &n; // single pointer
    int **p2 = &p; // doulbe pointer
    int ***p3 = &p2; // triple pointer
    cout<<p<<endl; // 0x61ff08
    cout<<&p<<endl; // 0x61ff04
    cout<<p2<<endl; // 0x61ff04
    cout<<&p2<<endl; // 0x61ff00
    cout<<p3<<endl; // 0x61ff00

    // mpdify the value
    ***p3 = ***p3+5;
    cout<<n<<endl; // 15

    fun(p);
    cout<<n<<endl; // 20

}