#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// T.C -> O(n)
// S.C -> O(n)

int longestRectangle(vector<int>arr, int n)
{
    vector<int>left(n);
    vector<int>right(n);
    stack<int>st;
    // next smaller element on left
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty())
    {
        left[st.top()] = -1;
        st.pop();
    }

    // next smaller element on right
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        right[st.top()] = n;
        st.pop();
    }

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, arr[i]*(right[i]-left[i]-1));
    }

    return ans;
};

int main()
{
    vector<int>arr = {2,1,5,6,2,3};

    int ans = longestRectangle(arr, 6);
    cout<<ans<<endl; // 10;
}