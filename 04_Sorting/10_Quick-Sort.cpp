#include<iostream>
using namespace std;

// T.C Average case -> O(n logn), S.C -> O(logn)
// T.C Worst case -> O(n^2), S.C -> O(n)

int partition(int arr[], int start, int end)
{
    int pos = start;
    for(int i=start; i<=end; i++)
    {
        if(arr[i]<=arr[end])
        {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    return pos-1;
}

void quicksort(int arr[], int start, int end)
{
    if(start>=end)
    return;
    
    int pivot = partition(arr, start, end);
    // Left side
    quicksort(arr, start, pivot-1);
    // Right side
    quicksort(arr, pivot+1, end);
}

int main()
{
    int arr[10] = {5,8,3,2,6,9,7,4,1,10};
    quicksort(arr, 0, 9);
    for(int i=0; i<10; i++)
    cout<<arr[i]<<" "; // 1 2 3 4 5 6 7 8 9 10 
}