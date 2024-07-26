#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// T.C -> O(n)
// S.C -> O(n)

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    vector<int>ans (n, -1);
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[i]<arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
    
}

int main()
{
    vector<int>arr = {6,8,0,1,3};

    arr = nextSmallerElement(arr, arr.size());

    //print value
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" "; // 0 0 -1 -1 -1
    }
}