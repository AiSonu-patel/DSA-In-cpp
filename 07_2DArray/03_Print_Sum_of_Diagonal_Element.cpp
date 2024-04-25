#include<iostream>
using namespace std;

void printDigSum(int arr[][3], int row, int col)
{
    int first = 0;
    int second = 0;
    int i=0;
    while(i<row)
    {
        first += arr[i][i];
        i++;
    }
    i=0;
    int j=col-1;
    while(j>=0)
    {
        second += arr[i][j];
        i++;
        j--;
    }

    cout<<first<<" "<<second<<" ";

}

int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    printDigSum(arr, 3, 3);
}