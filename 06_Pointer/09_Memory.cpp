#include<iostream>
using namespace std;

int main()
{
    // verible ke ly heap memory allocation karo
    int *p = new int;
    *p = 10; // value assign
    cout<<*p<<endl;

    float *p2 = new float;
    *p2 = 3.5;
    cout<<*p2<<endl;

    int n;
    cout<<"Enter the Array size ";
    cin>>n;

    int *p3 = new int[n];
    // enter the values in array
    for(int i=0; i<n; i++)
    p[i]=i+1;

    // print the array values;
    for(int i=0; i<n; i++)
    cout<<p[i]<<" ";

    //delete the heap memory allocation
    delete p;
    delete p2;
    delete p3;
}