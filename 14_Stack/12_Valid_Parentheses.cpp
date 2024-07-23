#include<iostream>
#include<stack>
using namespace std;

// check parentheses is valid or not
// T.C -> O(n)
// S.C -> O(n)

bool check(string str)
{
    stack<char>s;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        s.push(str[i]);
        else
        {
            if(s.empty())
            return 0;
            else if(str[i]==')')
            {
                if(s.top()!='(')
                return 0;
                else
                s.pop();
            }
            else if(str[i]==']')
            {
                if(s.top()!='[')
                return 0;
                else
                s.pop();
            }
            else
            {
                if(s.top()!='{')
                return 0;
                else
                s.pop();
            }
        }
    }
    return s.empty();

};

int main()
{
    string str = "[()]{[]}";
    cout<<check(str)<<endl; // 1

    return 0;
}