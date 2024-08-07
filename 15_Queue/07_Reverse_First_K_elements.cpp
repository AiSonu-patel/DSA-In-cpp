#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Reverse First K elements of Queue
// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(n)

queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    stack<int> st;
    while (k--)
    {
        st.push(q.front());
        q.pop();
    }
    int n = q.size();
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    while (n--)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
};

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // modifyQueue the queue
    q = modifyQueue(q, 3);

    // print all element
    int n = q.size();
    while (n--)
    {
        cout << q.front() << " "; // 3 2 1 4 5
        q.push(q.front());
        q.pop();
    }
}