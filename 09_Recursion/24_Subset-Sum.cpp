#include<iostream>
#include <vector>
using namespace std;

// T.C -> O(2^n)
// S.C -> O(n)

void subset(int arr[], int index, int n, int sum)
{
    if(index==n)
    {
        cout<<sum<<endl;
        return;
    }

    // No selected
    subset(arr, index+1, n, sum);
    // selected
    subset(arr, index+1, n, sum+arr[index]);

}

int main()
{
    int arr[3] = {1,2,3};
    int sum=0;

    subset(arr, 0, 3, sum); // 0, 3, 2, 5, 1, 4, 3, 6
}