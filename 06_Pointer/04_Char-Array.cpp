#include<iostream>
using namespace std;

int main()
{
    char arr[5] = "1234";
    char *ptr = arr;

    //print the value
    cout<<arr<<endl; // 1234
    cout<<ptr<<endl; // 1234

    //print the address
    cout<<(void*)arr<<endl; // 0x61ff06
    cout<<(void*)ptr<<endl; // 0x61ff06
    cout<<static_cast<void*>(arr)<<endl; // 0x61ff06

    char name = 'a';
    // cout<<&name<<endl; random answer
    cout<<(void*)name<<endl; // 0x61

    return 0;
};