#include<iostream>
using namespace std;

// Search Insert Position

int SearchInsertPosition(int arr[], int n, int x)
{
    int start = 0, end = n-1, ans = n, mid;
    while(start<=end)
    {
        mid = start+(end-start)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]<x)
        start = mid+1;
        else
        {
            ans = mid;
            end = mid-1;
        }
    }

    return ans;
}

int main()
{
    int arr[1000];
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    int target;
    cout<<"Enter the target: ";
    cin>>target;

    cout<<SearchInsertPosition(arr, n, target);

    return 0;
}