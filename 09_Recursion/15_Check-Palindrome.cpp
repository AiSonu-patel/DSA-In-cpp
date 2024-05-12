#include<iostream>
using namespace std;

bool checkPalindrome(string str, int start, int end)
{
    if(start>=end)
    return 1;

    if(str[start]!=str[end])
    return 0;
    else
    return checkPalindrome(str, start+1, end-1);
}

int main()
{
    string str = "mom";
    int start=0, end=str.size()-1;
    cout<<checkPalindrome(str, start, end); // 1

    return 0;
}