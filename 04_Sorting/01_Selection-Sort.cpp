#include<iostream>
using namespace std;

int main()
{
    // Selection Sorting Algorithim
    int arr[6] = {10,5,8,4,1,2};

    for(int i=0; i<5; i++)
    {
        int indx = i;
        for(int j=i+1; j<6; j++)
        {
            if(arr[j]<arr[indx])
            indx = j;
        }
        swap(arr[i], arr[indx]);
    }

    // Print Array Element
    for(int i=0; i<6; i++)
    {
        cout<<arr[i]<<" ";
    }
}