#include<iostream>
using namespace std;

int targetsum(int arr[], int index, int n, int sum)
{
    if(sum==0)
    return 1;

    if(index==n || sum<0)
    return 0;

    long long ans = targetsum(arr, index+1, n, sum);
    ans += targetsum(arr, index, n, sum-arr[index]);

    return ans%1000000007;
}

int main()
{
    int arr[] = {2,3,4};
    int sum = 6;
    cout<<targetsum(arr, 0, 3, sum); // 3
}