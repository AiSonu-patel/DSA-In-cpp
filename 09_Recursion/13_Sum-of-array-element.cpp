#include<iostream>
using namespace std;

// T.C -> O(n)
// S.C -> O(n^2)

int sum(int arr[], int index, int n)
{
    if(index==n)
    return 0;

    return arr[index]+sum(arr, index+1, n);
}

int main()
{
    int arr[6] = {1,2,3,4,5,6};
    int n = 6;

    cout<<sum(arr, 0, n-1); // 15
}