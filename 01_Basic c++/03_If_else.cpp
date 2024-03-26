#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the yout Age: ";
    int age;
    cin>>age;
    if(age>=18)
    {
        cout<<"You are Eligible for voting";
    }
    else
    {
        cout<<"You are not Eligible for voting";
    }
}