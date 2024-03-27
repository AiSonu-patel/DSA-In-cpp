#include<iostream>
using namespace std;

int main()
{
    //{<<. >>} > {&, |, ^}

    // & operator
    int ans = 2&3;
    cout<<ans<<endl; // 2

    // | operator
    int ans1 = 2|3;
    cout<<ans1<<endl; // 3

    // ^ operator
    int ans2 = 2^3;
    cout<<ans2<<endl; // 1

    // << --> Left sift
    int ans3 = 2<<3;
    cout<<ans3<<endl; // 16

    // >> --> Right sift
    int ans4 = 18>>3;
    cout<<ans4<<endl; // 2

    // ~ --> complement
    int ans5 = ~5;
    cout<<ans5<<endl; // -6
}