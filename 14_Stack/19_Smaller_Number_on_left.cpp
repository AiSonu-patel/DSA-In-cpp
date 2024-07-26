#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// T.C -> O(n)
// S.C -> O(n)

vector<int> smallerNumberLeft(vector<int> arr, int n)
{
    stack<int>st;
    vector<int>ans(n, -1);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[i] < arr[st.top()])
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

    arr = smallerNumberLeft(arr, arr.size());

    //print value
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" "; // -1 6 -1 0 1
    }
}