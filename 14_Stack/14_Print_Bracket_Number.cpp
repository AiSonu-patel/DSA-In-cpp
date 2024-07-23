#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// print bracket number

vector<int> printBracket(string str)
{
    int count=0;
    stack<int>st;
    vector<int>ans;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(')
        {
            count++;
            st.push(count);
            ans.push_back(count);
        }
        else if(str[i]==')')
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
};

int main()
{
    string str = {"(aa(bbc))p(de)"};

    vector<int> ans = printBracket(str);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}