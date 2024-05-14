#include<iostream>
#include <vector>
using namespace std;

// T.C -> O(n long2n)
// S.C -> O(n)

void merge(int arr[], int start, int mid, int end)
{
    vector<int> ans(end-start+1);
    int index=0, left=start, right=mid+1;
    while(left <= mid && right <= end)
    {
        if(arr[left]<=arr[right])
        {
            ans[index] = arr[left];
            index++;
            left++;
        }
        else
        {
            ans[index] = arr[right];
            index++;
            right++;
        }
    }

    // left array is not empty yet
    while(left<=mid)
    {
        ans[index] = arr[left];
        index++;
        left++;
    }

    // right array is not empty yet
    while(right<=end)
    {
        ans[index] = arr[right];
        index++;
        right++;
    }

    // put these value in array
    index=0;
    while(start<=end)
    {
        arr[start] = ans[index];
        start++;
        index++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if(start==end)
    return;

    int mid = start+(end-start)/2;
    // left side
    mergeSort(arr, start, mid);
    // right side
    mergeSort(arr, mid+1, end);

    // merge
    merge(arr, start, mid, end);
}

int main()
{
    int arr[10] = {5,8,3,9,1,2,4,6,7,10};
    mergeSort(arr, 0, 9);

    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" "; // 1 2 3 4 5 6 7 8 9 10 
    }
}