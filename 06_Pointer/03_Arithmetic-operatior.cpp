#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};

    int *ptr = arr;
    for(int i=0; i<5; i++)
    {
        cout<<*ptr<<" "; // 1 2 3 4 5 
        ptr++;
    }
    cout<<endl;

    int *p = &arr[4];
    for(int i=4; i>=0; i--)
    {
        cout<<*p<<" "; // 5 4 3 2 1
        p--;
    }
}