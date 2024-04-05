#include<iostream>
using namespace std;

int main()
{
    // Decscending Order
    int arr[100];
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array element: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=n-1; i>0; i--)
    {
        for(int j=0; j<i; j++)
            if(arr[j]<arr[j+1])
            swap(arr[j], arr[j+1]);
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}