#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // name, age

    // pair<string, int>p;
    // two method
    // p = make_pair("sonu",21);
    // p.first = "sonu";
    // p.second = 21;
    // cout<<p.first<<" "<<p.second<<endl; // sonu 21

    // name, age, weight
    // pair<string,pair<int,int>>p;
    // p.first = "sonu";
    // p.second.first = 21;
    // p.second.second = 50;

    // p = make_pair("sonu", make_pair(21,50));
    // cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl; // sonu 21 50

    pair<pair<string, int>,int>p;
    // p = make_pair(make_pair("sonu",21),50);

    p.first.first = "sonu";
    p.first.second = 21;
    p.second = 50;
    cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl; // sonu 21 50
}