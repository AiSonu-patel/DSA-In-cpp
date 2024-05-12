#include<iostream>
using namespace std;

// T.C -> O(log2n)
// S.C -> O(log2n)

bool searchElem(int arr[], int start, int end, int k)
{
    if(start>end)
    return 0;
    
    int mid = start +(end-start)/2;
    if(arr[mid]==k)
    return 1;
    else if(arr[mid]<k)
    return searchElem(arr, mid+1, end, k);
    else
    return searchElem(arr, start, mid-1, k);
}

int main()
{
    int arr[6] = {8,5,3,7,1,9};
    int x = 19;
    cout<<searchElem(arr, 0, 5, x); // 1 (true)
}