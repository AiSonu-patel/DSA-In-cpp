#include<iostream>
using namespace std;

int main()
{
    string str = "sonu";
    int size = 0;
    while(str[size]!=0)
    {
        size++;
    }
    cout<<size; // 4
}