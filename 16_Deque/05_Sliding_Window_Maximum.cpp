#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// Sliding window maximum k
// T.C -> O(n);

int main()
{
    int nums[] = {4,3,7,5,2,3,1,2,8,7};
    int n = 10;
    int k = 4;

    vector<int>ans;
    deque<int>d;
    for(int i=0; i<k-1; i++)
    {
        if(d.empty())
        d.push_back(i);
        else
        {
            while(!d.empty() && nums[i]>nums[d.back()])
            d.pop_back();

            d.push_back(i);
        }
    }

    for(int i=k-1; i<n; i++)
    {
        while(!d.empty() && nums[i]>nums[d.back()])
        d.pop_back();
        d.push_back(i);

        if(d.front()<=i-k)
        d.pop_front();

        ans.push_back(nums[d.front()]);
    }
    
    

    // print ans value
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" "; // 7 7 7 5 3 8 8
    }
}