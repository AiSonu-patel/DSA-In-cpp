#include<iostream>
using namespace std;

// T.C -> O(2^n)

bool find(int arr[], int index, int n, int target)
{
    if(target==0)
    return 1;

    if(index==n || target<0)
    return 0;

    return find(arr, index+1, n, target) || find(arr, index+1, n, target-arr[index]);
}

int main()
{
    int arr[4] = {3,6,4,5};
    int target = 12;

    cout<<find(arr, 0, 4, target); // 1
}