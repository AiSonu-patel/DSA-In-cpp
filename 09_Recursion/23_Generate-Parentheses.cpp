#include<iostream>
#include <vector>
using namespace std;

// T.C O(2^n)

void parenthesis(int n, int left, int right, vector<string>&ans, string &temp)
{
    if(left+right== 2*n)
    {
        ans.push_back(temp);
        return;
    }
        
    if(left<n)
    {
        temp.push_back('(');
        parenthesis(n, left+1, right, ans, temp);
        temp.pop_back();
    }
        
    if(right<left)
    {
        temp.push_back(')');
        parenthesis(n, left, right+1, ans, temp);
        temp.pop_back();
    }
}

int main()
{
    int n = 3;
    vector<string> ans;
    string temp;

    parenthesis(n, 0, 0, ans, temp);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<endl; // [((())), (()()), (())(), ()(()), ()()()]
}