#include<iostream>
using namespace std;

int findsubset(int arr[], int index, int n, int sum)
{
    if(index==n)
    return sum==0;

    long long ans = findsubset(arr, index+1, n, sum);
    ans+= findsubset(arr, index+1, n, sum-arr[index]);

    return ans%1000000007;
}

int main()
{
    int arr[] = {1,0};
    int sum = 1;
    cout<<findsubset(arr, 0, 2, sum); // 2
}