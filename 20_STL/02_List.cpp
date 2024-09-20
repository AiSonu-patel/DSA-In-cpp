#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // list like a DLL
    list<int>l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    l.push_front(15);

    // cout<<l.front()<<endl; // 15
    // cout<<l.back()<<endl; // 50
    // cout<<l.size()<<endl; // 5

    // l.pop_back();
    // l.pop_front();
    // cout<<l.back()<<endl; // 20
    // cout<<l.front()<<endl; // 40
    // cout<<l.size()<<endl; // 3
    // cout<<l.empty()<<endl; // 0

    for(auto it = l.begin(); it!= l.end(); it++)
    {
        cout<<*it<<" "; // 15 20 30 40 50
    }
    cout<<endl;
    // reverse value print
    for(auto it = l.rbegin(); it!=l.rend(); it++)
    {
        cout<<*it<<" "; // 50 40 30 20 15
    } 
}