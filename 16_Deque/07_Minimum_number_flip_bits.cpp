#include<iostream>
#include<queue>
using namespace std;

// Minimum Number of k consecutive flip bits
// T.C -> O(n)
// S.C -> O(k)

int minimumFlip(int nums[], int n, int k)
{
    queue<int>q;
    int flip = 0;
    for(int i=0; i<n; i++)
    {
        if(!q.empty() && q.front()<i)
        q.pop();

        if(q.size()%2==nums[i])
        {
            if(i+k-1>=n)
            return -1;

            q.push(i+k-1);
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