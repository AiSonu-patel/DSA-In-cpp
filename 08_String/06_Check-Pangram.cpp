#include<iostream>
#include <vector>
using namespace std;

bool pangram(string str)
{
    vector<bool>alpha (26, 0);
    for(int i=0; i<str.size(); i++)
    {
        alpha[str[i]-'a'] = 1;
    }

    for(int i=0; i<26; i++)
    {
        if(alpha[i]==0)
        return 0;
    }
    return 1;
}

int main()
{
    string str = "bawdsjogflickquartzvexnymph";

    cout<<pangram(str); // 1
}