#include<iostream>
using namespace std;

int main()
{
    int arr[6] = {1,2,3,4,5,6};
    int i=0, j=5;

    while(i<j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for(int i=0; i<6; i++)
    { 
        cout<<arr[i]<<" "; // 6 5 4 3 2 1
    }

    return 0;
}