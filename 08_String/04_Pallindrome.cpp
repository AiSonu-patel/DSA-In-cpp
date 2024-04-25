#include<iostream>
using namespace std;

int main()
{
    string str = "naman";
    int start = 0, end = str.size()-1;
    while(start<end)
    {
        if(str[start] != str[end])
        {
            cout<<"Not a pallindrome";
            return 0;
        }
        start++;
        end--;
    }
    cout<<"It is a palindrome";
}