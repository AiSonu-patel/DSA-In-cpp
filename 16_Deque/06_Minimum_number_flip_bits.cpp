#include<iostream>
using namespace std;

// Minimum Number of k consecutive flip bits
// T.C -> O(n k)
// S.C -> O(1)

int minimumFlip(int nums[], int n, int k)
{
    int flip = 0;
    for(int i=0; i<n; i++)
    {
        if(nums[i]==0)
        {
            if(i+k-1>=n)
            return -1;

            for(int j=i; j<=i+k-1; j++)
            {
                nums[j] = !nums[j];
            }
            flip++;
        }
    }
    return flip;
}

int main()
{
    int nums[] = {0,1,0,1};
    int n = 4;
    int k = 2;

    cout<<minimumFlip(nums, n, k)<<endl; // 2
    
}