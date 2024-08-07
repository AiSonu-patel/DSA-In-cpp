#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;

    // pushed into the queue
    q.push(10);
    q.push(40);
    q.push(123);

    // popped from the queue
    q.pop(); // 10

    // queue front
    cout<<q.front()<<endl; // 40

    // queue back
    cout<<q.back()<<endl; // 123

    // queue size
    cout<<q.size()<<endl; // 2

    // queue empty
    cout<<q.empty()<<endl;

}