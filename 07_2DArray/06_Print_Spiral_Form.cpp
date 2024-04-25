#include<iostream>
using namespace std;

void spiral(int arr[][6], int row, int col)
{
    int top=0, right=col-1, bootom=row-1, left=0;
    while(left<=right && top<=bootom)
    {
        for(int i=left; i<=right; i++)
        cout<<arr[top][i]<<" ";
        top++;
        for(int i=top; i<=bootom; i++)
        cout<<arr[i][right]<<" ";
        right--;
        if(top<=bootom)
        {
            for(int i=right; i>=left; i--)
            cout<<arr[bootom][i]<<" ";
            bootom--;
        }
        if(left<=right)
        {
            for(int i=bootom; i>=top; i--)
            cout<<arr[i][left]<<" ";
            left++;
        }
    }
}

int main()
{
    int arr[6][6] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};

    spiral(arr, 6, 6); // 1 2 3 4 5 6 12 18 24 30 36 35 34 33 32 31 25 19 13 7 8 9 10 11 17 23 29 28 27 26 20 14 15 16 22 21
    
}