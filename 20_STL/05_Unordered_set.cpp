#include<iostream>
#include<unordered_set>
using namespace std;

// It store unique elements
// it store elements in unordered way
// it is insert, search, delete O(1)
// it uses hashing technique to achieve it

int main()
{
    unordered_set<int>s;
    // unordered_multiset<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(10);
    s.insert(15);

    for(auto it=s.begin(); it!=s.end(); it++)
    cout<<*it<<" "; // 15 30 20 10 
}