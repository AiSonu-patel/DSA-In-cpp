#include<iostream>
using namespace std;

int main()
{
    //{&&, ||, !}
    int a, b, c;
    cout<<"Enter the value of a: "; // 2
    cin>>a;
    cout<<"Enter the value of b: "; // 5
    cin>>b;
    cout<<"Enter the value of c: "; // 1
    cin>>c;

    // && --> AND Oper.
    if(a>b && a>c)
    cout<<"Yes";
    else
    cout<<"No"; // Ans

    // || --> OR Oper.
    // char ch;
    // cout<<"Enter the char: "; // a
    // cin>>ch;

    // if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    // cout<<"Vowel"; // Ans
    // else
    // cout<<"Consonant";

    // ! --> NOT Oper.
    // cout<<!23; // 0
    // cout<<!0; // 1

}