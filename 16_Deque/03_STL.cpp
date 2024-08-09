#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int>d;
    d.push_back(10); // 10
    d.push_front(30); // 30 10
    cout<<d.front()<<endl; // 30
    d.pop_front(); // 10
    cout<<d.front()<<endl; // 10
}