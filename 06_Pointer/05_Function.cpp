#include<iostream>
using namespace std;

void incr(int n)
{
    n++;
}

void incr1(int *ptr)
{
    *ptr = *ptr+1;
}

void incr2(int &a)
{
    a++;
}

void dob(int *p) // int p[]
{
    for(int i=0; i<5; i++)
    p[i] = 2*p[i];
}

void swapping(int *p1, int *p2) // pass by pointer
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void swapping1(int &p1, int &p2) // pass by reference
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    int a = 10;
    int temp = a;
    incr(a);
    cout<<a<<endl; // 10;
    incr1(&a); // pass by pointer
    cout<<a<<endl; // 11;
    incr2(a);
    cout<<a<<endl; // 12;

    int arr[5] = {1,2,3,4,5};
    dob(arr); // pass by address
    for(int i=0; i<5; i++)
    cout<<arr[i]<<" "; // 2 4 6 8 10

    cout<<endl;

    int first=10;
    int second=20;
    // swapping(&first, &second);
    // cout<<first<<" "<<second<<endl; 20, 10

    swapping1(first, second);
    cout<<first<<" "<<second<<endl; // 20, 10
}