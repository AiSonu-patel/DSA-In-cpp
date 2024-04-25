#include<iostream>
using namespace std;

int main()
{
    string str = "1.1.1.1";

    int index = 0;
    string ans;
    while(index < str.size())
    {
        if(str[index] == '.')
        ans = ans+"[.]";
        else
        ans = ans+str[index];

        index++;
    }

    cout<<ans; // 1[.]1[.]1[.]1
}