#include<iostream>
#include <vector>
using namespace std;

vector<int> fastLastOccuss(int arr[], int n, int x)
{
    int last=-1, first=-1, start=0, end=n-1, mid;
    while(start<=end)
    {
        mid = start + (end-start)/2;
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

    start=0, end=n-1;
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

    vector<int>a(2);
    a[0] = first;
    a[1] = last;

    return a;
}

int main()
{
    int arr[1000];
    int n;
    cout<<"Enter the array size: ";
    cin>>n;

    cout<<"Enter the array element: ";
    for(int i=0; i<n; i++)
    cin>>arr[i];

    int target;
    cout<<"Enter the Targert: ";
    cin>>target;

    vector<int>ans = fastLastOccuss(arr, n, target);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}