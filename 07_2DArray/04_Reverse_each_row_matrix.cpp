#include<iostream>
using namespace std;

int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int row=3, col=3;
    for(int i=0; i<row; i++)
    {
        int start=0, end = col-1;
        while(start<end)
        {
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
}