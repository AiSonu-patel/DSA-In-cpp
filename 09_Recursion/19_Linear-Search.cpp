#include<iostream>
using namespace std;

bool find(int arr[], int index, int x)
{
    if(index==-1)
    return 0;

    if(arr[index]==x)
    return 1;

    return find(arr, index-1, x);
}

int main()
{
    int arr[6] = {2,8,7,5,4,1};
    int x = 3;
    cout<<find(arr, 5, x); // 0
}