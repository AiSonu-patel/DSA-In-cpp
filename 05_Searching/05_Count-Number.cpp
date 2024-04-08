#include<iostream>
using namespace std;

int CountNumber(int arr[], int n, int x)
{
    int start = 0, end = n-1, mid, first = 0, last = -1;
    while(start<=end)
    {
        mid = start+(end-start)/2;
        if(arr[mid]==x)
        {
            first = mid;
            end = mid-1;
        }
        else if(arr[mid]<x)
        start = mid+1;
        else
        end = mid-1;
    }

    start = 0, end = n-1;
    while(start<=end)
    {
        mid = start+(end-start)/2;
        if(arr[mid]==x)
        {
            last = mid;
            start = mid+1;
        }
        else if(arr[mid]<x)
        start = mid+1;
        else
        end = mid-1;
    }

    int ans = last-first+1;

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
    cout<<"Enter the Target: ";
    cin>>target;

    cout<<CountNumber(arr, n, target);

    return 0;
}