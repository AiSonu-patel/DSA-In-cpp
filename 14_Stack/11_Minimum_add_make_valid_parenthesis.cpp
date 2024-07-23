#include<iostream>
using namespace std;

// Minimum add to make parenthesis valid
// T.C -> O(n)
// S.C -> O(1)

int addParenthesis(string str)
{
    int open = 0;
    int count=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(')
        open++;
        else
        {
            if(open==0)
            count++;
            else
            open--;
        }
    }
    return open+count;
};

int main()
{
    string str = "))(())))";
    cout<<addParenthesis(str)<<endl; // 4

    return 0;
}