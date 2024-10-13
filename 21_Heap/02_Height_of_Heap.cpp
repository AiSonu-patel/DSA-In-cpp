#include <iostream>
using namespace std;

int heapHeight(int N, int arr[])
{
    // code here
    if (N == 1)
        return 1;

    int height = 0;
    while (N > 1)
    {
        height++;
        N /= 2;
    }

    return height;
}

int main()
{
    int arr[] = {1, 3, 6, 5, 9, 8};
    int N = 6;

    int ans = heapHeight(N, arr);
    cout<<ans<<" "; 
    // output = 2
}