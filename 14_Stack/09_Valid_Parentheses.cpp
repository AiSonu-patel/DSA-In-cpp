#include<iostream>
using namespace std;

// T.C -> O(n)
// S.C -> O(1)

bool check(string str)
{
    int left=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(')
        left++;
        else
        {
            if(left==0)
            return 0;
            else
            left--;
        }
    }
    return left==0;
};

int main()
{
    string str = "(()(()))";
    cout<<check(str)<<endl; // 1

    return 0;
}