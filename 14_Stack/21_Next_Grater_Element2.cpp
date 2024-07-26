#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// T.C -> O(n)
// S.C -> O(n)

vector<int> nextGraterElement2(vector<int> arr, int n)
{
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=0; i<2*n; i++)
    {
        while(!st.empty() && arr[i%n]>arr[st.top()])
        {
            ans[st.top()] = arr[i%n];
            st.pop();
        }
        st.push(i%n);
    }

    return ans;
}

int main()
{
    vector<int>arr = {6,8,0,1,3};

    arr = nextGraterElement2(arr, arr.size());

    //print value
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" "; // 8 -1 1 3 6
    }
}