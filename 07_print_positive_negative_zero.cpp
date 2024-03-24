#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter any num.: ";
    cin>>num;

    if(num>0)
    {
        cout<<"Positive No.";
    }
    else if(num==0)
    {
        cout<<"Zero No.";
    }
    else
    {
        cout<<"Negative No.";
    }
}