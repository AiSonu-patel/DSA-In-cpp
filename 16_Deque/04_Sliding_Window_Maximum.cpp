#include<iostream>
#include<vector>
using namespace std;

// Sliding window maximum k
// T.C -> O(n k);

int main()
{
    int nums[] = {4,3,7,5,2,3,1,2,8,7};
    int n = 10;
    int k = 4;

    vector<int>ans;

    for(int i=0; i<=n-k; i++)
    {
        int total = -1;
        for(int j=i; j<i+k; j++)
        {
            total = max(total, nums[j]);
        }
        ans.push_back(total);
    }

    // print ans value
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" "; // 7 7 7 5 3 8 8
    }
}