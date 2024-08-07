#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// First negative integer in every window of size k
// T.C -> O(n)
// S.C -> O(k)

int main()
{
    int arr[] = {2,-3,-4,-2,7,8,9,-10};
    int n = 8;
    int k = 3;

    queue<int>q;
    vector<int>ans;
    for(int i=0; i<k-1; i++)
    {
        if(arr[i]<0)
        q.push(i);
    }

    for(int i=k-1; i<n; i++)
    {
        if(arr[i]<0)
        q.push(i);
        
        if(q.empty())
        ans.push_back(0);
        else
        {
            if(q.front()<=i-k)
            q.pop();
            
            if(q.empty())
            ans.push_back(0);
            else
            ans.push_back(arr[q.front()]);
        }
    }

    // print ans value
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" "; // -3 -3 -4 -2 0 -10
    }

    return 0;
}