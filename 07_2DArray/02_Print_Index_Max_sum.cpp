#include<iostream>
#include <climits>
using namespace std;

void printrowMax(int arr[][4], int row, int col)
{
    int sum=INT_MIN;
    int index = -1;

    for(int i=0; i<row; i++)
    {
        int total = 0;
        for(int j=0; j<col; j++)
        {
            total += arr[i][j];
        }
        if(total>sum)
        {
            sum = total;
            index = i;
        }
    }
    cout<<index<<" ";
}

int main()
{
    int arr[4][4] = {3, 6, 4, 2, 7, 8, 11, 5, 9, 3, 12, 1, 17, 8, 5, 9};
    
    printrowMax(arr, 4, 4);  // 2 row 
}