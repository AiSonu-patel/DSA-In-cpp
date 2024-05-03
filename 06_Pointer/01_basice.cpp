#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    // Print address
    cout<<&a<<endl; // 0x61ff04
    int *ptr = &a;
    cout<<ptr<<endl; // 0x61ff04

    float m = 1.2;
    float *ptr1 = &m;
    cout<<ptr1<<endl; // 0x61ff00

    //print the *ptr size
    cout<<sizeof(ptr1)<<endl; // 4

    cout<<ptr<<endl; // address of a 
    cout<<*ptr<<endl; // value inside a
}