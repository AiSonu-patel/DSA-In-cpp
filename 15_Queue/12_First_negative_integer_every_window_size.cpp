#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// First negative integer in every window of size k
// T.C -> O(n k)
// S.C -> O(k)

int display(queue<int>q)
{
    while(!q.empty())
    {
        if(q.front()<0)
        return q.front();

        q.pop();
    }
    return 0;
}

int main()
{
    int arr[] = {2,-3,-4,-2,7,8,9,-10};
    int n = 8;
    int k = 3;

    queue<int>q;
    for(int i=0; i<k-1; i++)
    q.push(arr[i]);

    vector<int>ans;
    for(int i=k-1; i<n; i++)
    {
        q.push(arr[i]);
        ans.push_back(display(q));
        q.pop();
    }

    // print ans value
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" "; // -3 -3 -4 -2 0 -10
    }

    return 0;
}