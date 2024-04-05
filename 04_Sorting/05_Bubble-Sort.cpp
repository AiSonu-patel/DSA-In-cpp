#include<iostream>
using namespace std;

int main()
{
    // Ascending Order
    int arr[1000];
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array element: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(int i=0; i<n-1; i++)
    {
        bool swapped = 0;
        for(int j=n-1; j>i; j--)
        {
            if(arr[j] < arr[j-1])
            {
                swapped = 1;
                swap(arr[j], arr[j-1]);
            }
        }
        if(swapped==0)
        break;
    }

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}