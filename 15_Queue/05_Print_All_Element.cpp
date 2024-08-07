#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    q.push(45);

    // print all queue values
    int n = q.size();
    while(n--)
    {
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
}