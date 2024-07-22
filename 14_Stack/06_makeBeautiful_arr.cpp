#include<iostream>
#include<stack>
#include <vector>
using namespace std;

vector<int> makeBeautiful(vector<int> arr)
{
    stack<int>st;
    for(int i=0; i<arr.size(); i++)
    {
        if(st.empty())
        {
            st.push(arr[i]);
        }
        else if(arr[i]>=0)
        {
            if(st.top()>=0)
            {
                st.push(arr[i]);
            }
            else
            {
                st.pop();
            }
        }
        else
        {
            if(st.top()<0)
            {
                st.push(arr[i]);
            }
            else
            {
                st.pop();
            }
        }
    }
    vector<int>ans(st.size());
    int i = st.size()-1;
    while(!st.empty())
    {
        ans[i] = st.top();
        st.pop();
        i--;
    }
    return ans;
};

int main()
{
    vector<int>arr = {4,2,-2,1};
    vector<int> ans = makeBeautiful(arr);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" "; // 4 1 
    }
}