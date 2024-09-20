#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Unique keys are present, Duplicate keys are not allowed
// Not neccessary it should be in sorted form
// Hashing 
// search, insert, delete constant time execution

int main()
{

    unordered_map<int, int>m;
    m.insert(make_pair(20, 200));
    m.insert(make_pair(20, 300));
    m.insert(make_pair(30, 400));
    m.insert(make_pair(40, 500));

    m[20]=70;

    for(auto it=m.begin(); it!=m.end(); it++)
    cout<<it->first<<" "<<it->second<<endl;
}