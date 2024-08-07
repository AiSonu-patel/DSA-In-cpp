#include<iostream>
#include<queue>
using namespace std;

// Implement stack using queue

class Stack
{
    public:
    queue<int>q1;
    queue<int>q2;

    bool empty()
    {
        return q1.empty()&&q2.empty();
    }

    void push(int x)
    {
        if(empty())
        q1.push(x);
        else if(q1.empty())
        q2.push(x);
        else
        q1.push(x);
    }

    int pop()
    {
        if(empty())
        return 0;
        else if(q1.empty())
        {
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int element = q2.front();
            q2.pop();
            return element;
        }
        else
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int element = q1.front();
            q1.pop();
            return element;
        }
    }

    int top()
    {
        if(empty())
        return 0;
        else if(q1.empty())
        return q2.back();
        else
        return q1.back();
    }

};

int main()
{
    Stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
}