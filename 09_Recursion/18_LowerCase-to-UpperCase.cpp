#include<iostream>
using namespace std;

void lowerToupper(string &str, int index)
{
    if(index==-1)
    return;

    str[index] = 'A'+str[index]-'a';

    lowerToupper(str, index-1);
}

int main()
{
    string str = "sonu";

    lowerToupper(str, str.size()-1);
    cout<<str;
}