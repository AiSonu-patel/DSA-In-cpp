#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// T.C -> O(n)
// S.C -> O(1)

int longestRectangle(vector<int>arr, int n)
{
    int ans=0;
    int index;
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            index = st.top();
            st.pop();
            if(!st.empty())
            ans = max(ans, arr[index]*(i-st.top()-1));
            else
            ans = max(ans, arr[index]*i);
        }
        st.push(i);
    }
    while(!st.empty())
    {
        index = st.top();
        st.pop();
        if(!st.empty())
        ans = max(ans, arr[index]*(n-st.top()-1));
        else
        ans = max(ans, arr[index]*n);
    }
    return ans;
};

int main()
{
    vector<int>arr = {2,1,5,6,2,3};

    int ans = longestRectangle(arr, 6);
    cout<<ans<<endl; // 10;
}