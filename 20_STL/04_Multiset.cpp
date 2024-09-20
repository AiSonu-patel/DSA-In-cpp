#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Duplicate elements will be present
// Sorted order
// Read-Black Tree, AVL 

int main()
{
    multiset<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(30);
    s.insert(40);

    s.erase(10);

    for(auto it=s.begin(); it!=s.end(); it++)
    cout<<*it<<" "; // 20 30 40 
}