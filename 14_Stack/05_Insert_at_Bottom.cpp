#include<iostream>
#include<stack>
using namespace std;

stack<int> insertAtBottom(stack<int>s, int x)
{
    stack<int>temp;
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(x);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    return s;
};

int main()
{
    stack<int>s;
    s.push(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(8);

    // Insert at bottom
    s = insertAtBottom(s, 2);
    cout<<s.top();
}