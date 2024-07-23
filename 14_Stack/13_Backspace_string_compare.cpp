#include<iostream>
#include<stack>
using namespace std;

// Backgrount string compare

bool check(string str1, string str2)
{
    stack<char>s;
    stack<char>t;

    for(int i=0; i<str1.size(); i++)
    {
        if(str1[i]=='#')
        {
            if(!s.empty())
            s.pop();
        }
        else
        {
            s.push(str1[i]);
        }
    }

    for(int i=0; i<str2.size(); i++)
    {
        if(str2[i]=='#')
        {
            if(!t.empty())
            t.pop();
        }
        else
        {
            t.push(str2[i]);
        }
    }

    return s==t;


};

int main()
{
    string str1 = "ab#c";
    string str2 = "ad#c";

    cout<<check(str1, str2)<<endl; // 1

    return 0;
}