#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// set is only store unique element
// it store value in sorted order (ascending)
// search, insert, delete -> O(log n)
// Generally Implement using Red-Black Tree
// we can sort it in descending order also using greater<type>

class Person
{
    public:
    int age;
    string name;

    bool operator < (const Person &other) const{
        return age < other.age;
    }
};

int main()
{
    // set<int>s; // 10 20 110 200 210
    // set<int, greater<int>>s;  // 210 200 110 20 10
    // insert
    // s.insert(10);
    // s.insert(20);
    // s.insert(210);
    // s.insert(200);
    // s.insert(20);
    // s.insert(10);
    // s.insert(110);

    // delete the element
    // s.erase(210);

    // search the element
    // if(s.find(200) !=s.end())
    // cout<<"Present\n";
    // else
    // cout<<"Absent\n";

    // count
    // if(s.count(201))
    // cout<<"Present\n";
    // else
    // cout<<"Absent\n";

    // cout<<s.count(210)<<endl; // 0

    // for(auto it = s.begin(); it!=s.end(); it++)
    // {
    //     cout<<*it<<" "; // 10 20 110 200 210
    // }

    set<Person>s;
    Person p1, p2, p3;
    p1.age = 21, p1.name = "sonu";
    p2.age = 17, p2.name = "satyam";
    p3.age = 30, p3.name = "rahul";

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);

    for(auto it=s.begin(); it!=s.end(); it++)
    {
        cout<<(*it).age<<" "<<(*it).name<<endl;
    }
}