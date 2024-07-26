#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// T.C -> O(n)
// S.C -> O(n)

vector<int> nextGraterElement(vector<int> arr, int n)
{
    vector<int>ans (n, -1);
    stack<int>st;
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()]<arr[i])
        {
            st.pop();
        }
        if(!st.empty())
        ans[i] = arr[st.top()];

        st.push(i);
    }

    return ans;
    
}

int main()
{
    vector<int>arr = {6,8,0,1,3};

    arr = nextGraterElement(arr, arr.size());

    //print value
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" "; // 8 -1 1 3 -1
    }
}