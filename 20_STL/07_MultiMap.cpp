#include<iostream>
#include<map>
using namespace std;

// It store data in key-value pair
// Duplicate elements are allowed
// it uses Red=Black Tree or AVL for implementation
// Insertion, deletion, and search operations have logarithmic time complexity O(log n)
// it is fast for most use cases.

int main()
{
    multimap<int,int>m;
    m.insert(make_pair(20,30));
    m.insert(make_pair(30,310));
    m.insert(make_pair(40,230));
    m.insert(make_pair(50,230));
    m.insert(make_pair(20,30));

    for(auto it=m.begin(); it!=m.end(); it++)
    cout<<it->first<<" "<<it->second<<endl;
}