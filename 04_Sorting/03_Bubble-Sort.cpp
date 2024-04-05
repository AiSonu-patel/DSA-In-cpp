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
    
    for(int i=n-2; i>=0; i--)
    {
        bool swaped = 0;
        for(int j=0; j<=i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swaped = 1;
                swap(arr[j], arr[j+1]);
            }
        }
        if(swaped==0)
        {
            break;
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}