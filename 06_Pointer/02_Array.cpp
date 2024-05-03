#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;
    //print the address of first element
    cout<<ptr<<endl;
    cout<<arr<<endl;
    cout<<arr+0<<endl;
    cout<<&arr[0]<<endl;

    //print the address of second element
    cout<<arr+1<<endl;
    cout<<&arr[1]<<endl;
    cout<<ptr+1<<endl;

    //print the value of first element
    cout<<*arr<<endl;
    cout<<*(arr+0)<<endl;
    cout<<*ptr<<endl;
    cout<<arr[0]<<endl;

    //print all the address
    for(int i=0; i<5; i++)
    {
        // cout<<&arr[i]<<" ";
        // cout<<arr<<" ";
        // cout<<arr+i<<" ";
        cout<<ptr+i<<" ";
    }
    cout<<endl;
    //print all the values
    for(int i=0; i<5; i++)
    {
        // cout<<arr[i]<<" ";
        // cout<<*(arr+i)<<" ";
        // cout<<ptr[i]<<" ";
        // cout<<*(ptr+i)<<" ";
        cout<<*ptr<<" ";
        ptr++;
    }

    // arithmetic operatior
}