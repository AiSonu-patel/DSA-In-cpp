#include<iostream>
using namespace std;

void wave(int arr[][4], int row, int col)
{
    for(int j=0; j<col; j++)
    {
        if(j%2==0)
        {
            for(int i=0; i<row; i++)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        else
        {
            for(int i=row-1; i>=0; i--)
            {
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

int main()
{
    int arr[4][4] = {3,6,4,2,7,8,11,5,9,3,12,1,17,8,5,9};

    wave(arr, 4, 4); // 3 7 9 17 8 3 8 6 4 11 12 5 9 1 5 2 

    // for(int i=0; i<4; i++)
    // {
    //     for(int j=0; j<4; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}