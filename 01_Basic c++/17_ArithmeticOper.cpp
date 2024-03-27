#include<iostream>
using namespace std;

int main()
{
    // increment operator
    int a = 10;
    // post incerement
    cout<<a++; //10
    cout<<endl<<a; //11

    int b = 2;
    // pre incerement
    cout<<endl<<++b; // 3
    cout<<endl<<b; // 3;

    // decrement operator
    int c = 5;
    // post decrement
    cout<<endl<<c--; //5
    cout<<endl<<c; // 4

    int d = 8;
    // pre decrement
    cout<<endl<<--d; //7
    cout<<endl<<d; // 7  

}