#include<iostream>
#include<stack>
using namespace std;

// Minimum add to make parenthesis valid
// T.C -> O(n)
// S.C -> O(n)

int addParenthesis(string str)
{
    stack<char>s;
    int count=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(')
        s.push(str[i]);
        else
        {
            if(s.empty())
            count++;
            else
            s.pop();
        }
    }
    return count+s.size();
};

int main()
{
    string str = "))(())))";
    cout<<addParenthesis(str)<<endl; // 4

    return 0;
}