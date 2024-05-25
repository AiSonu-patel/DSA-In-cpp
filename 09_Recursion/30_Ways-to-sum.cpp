#include<iostream>
#include <vector>
using namespace std;

int waySum(int arr[], int n, int sum)
{
    if(sum==0)
    return 1;

    if(sum<0)
    return 0;

    long long ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += waySum(arr, n, sum-arr[i]);
    }
    return ans%1000000007;
}

int main()
{
    int arr[] = {1,5,6};
    cout<<waySum(arr, 3, 7); // 6

    // Tower of hanoi
    
}