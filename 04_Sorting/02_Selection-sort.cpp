#include<iostream>
using namespace std;

int main()
{
    int arr[100];
    int n;
    cout<<"Enter the array size: ";
    cin>>n;

    cout<<"Enter the array element: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    for(int i=n-1; i>=1; i--)
    {
        int maxindx = i;
        for(int j=i-1; j>=0; j--)
        {
            if(arr[j] > arr[maxindx])
            {
                maxindx = j;
            }
        }
        swap(arr[i], arr[maxindx]);
    }
    
    // print arr element
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}