#include<iostream>
#include<stack>
#include <vector>
using namespace std;

int removeConsecutiveSame(vector<string> arr)
{
    stack<string>st;
    for(int i=0; i<arr.size(); i++)
    {
        if(st.empty())
        st.push(arr[i]);
        else if(st.top()==arr[i])
        st.pop();
        else
        st.push(arr[i]);
    }
    
    return st.size();
};

int main()
{
    vector<string>arr = {"ab", "aa", "aa", "bcd", "ab"};
    cout<<removeConsecutiveSame(arr); // 3
}