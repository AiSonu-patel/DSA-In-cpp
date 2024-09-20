#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Duplicate keys are allowed
// Not neccessary it should be in sorted form
// Hashing

int main()
{
    unordered_multimap<int,int>m;
    m.insert(make_pair(20, 200));
    m.insert(make_pair(20, 300));
    m.insert(make_pair(30, 400));
    m.insert(make_pair(40, 500));
    m.insert(make_pair(50, 600));
    m.insert(make_pair(50, 700));

    for(auto it=m.begin(); it!=m.end(); it++)
    cout<<it->first<<" "<<it->second<<endl;

}