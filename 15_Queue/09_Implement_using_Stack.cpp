#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// Implement queue using stack
// T.C -> 

class Queue
{
    stack<int>st1;
    stack<int>st2;

    public:
    bool empty()
    {
        return st1.empty()&&st2.empty();
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if(empty())
        return 0;
        else if(!st2.empty())
        {
            int element = st2.top();
            st2.pop();
            return element;
        }
        else
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            int element = st2.top();
            st2.pop();
            return element;
        }
    }

    int peek()
    {
        if(empty())
        return 0;
        else if(!st2.empty())
        return st2.top();
        else
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
};

int main()
{
    Queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
}