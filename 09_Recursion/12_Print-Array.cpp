#include<iostream>
using namespace std;

// T.C -> O(n)
// S.C -> O(n)

void print1(int arr[], int index, int n)
{
    if(index==n)
    {
        return;
    }
    cout<<arr[index]<<" ";
    print1(arr, index+1, n);
}

void print2(int arr[], int index)
{
    if(index==-1)
    return;

    print2(arr, index-1);
    cout<<arr[index]<<" ";
}

int main()
{
    int arr[6] = {1,2,3,4,5,6};
    int n = 6;

    print1(arr, 0, n); // 1 2 3 4 5 6
    cout<<endl;
    print2(arr, n-1);  // 1 2 3 4 5 6
}