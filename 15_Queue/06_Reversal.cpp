#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Queue Reversal
// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(n)

queue<int> reversal(queue<int>q)
{
    stack<int>st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    return q;
};

int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // reversal the queue
    q = reversal(q);

    // print all element
    int n = q.size();
    while(n--)
    {
        cout<<q.front()<<" "; // 5 4 3 2 1
        q.push(q.front());
        q.pop();
    }
}