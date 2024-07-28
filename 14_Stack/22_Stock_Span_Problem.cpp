#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Stock Span problem like next grater element on left
// T.C -> O(n)
// S.C -> O(n)

vector<int> stockSpanProblem(vector<int> arr, int n)
{
    stack<int>st;
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[i] > arr[st.top()])
        {
            ans[st.top()] = st.top()-i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        ans[st.top()] = st.top()+1;
        st.pop();
    }

    return ans;
};

int main()
{
    vector<int>arr = {100, 80, 55, 70, 60, 75, 85};
    arr = stockSpanProblem(arr, arr.size());

    // print value
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" "; // 1 1 1 2 1 4 6
    }
}