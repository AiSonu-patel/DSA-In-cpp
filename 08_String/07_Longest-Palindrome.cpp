#include<iostream>
#include <vector>
using namespace std;

int longestPalindrome(string str)
{
    vector<int> lower(26,0);
    vector<int> upper(26,0);

    for(int i=0; i<str.size(); i++)
    {
        if(str[i] >= 'a')
        {
            int index = str[i]-'a';
            lower[index]++;
        }
        else
        {
            int index = str[i]-'A';
            upper[index]++;
        }
    }
    int count = 0;
    bool odd = 0;
    for(int i=0; i<26; i++)
    {
        if(lower[i]%2==0)
        {
            count += lower[i];
        }
        else
        {
            count += lower[i]-1;
            odd = 1;
        }

        if(upper[i]%2==0)
        {
            count += upper[i];
        }
        else
        {
            count += upper[i]-1;
            odd = 1;
        }
    }
    return count+odd;
}

int main()
{
    string str = "abccccdd";
    
    cout<<longestPalindrome(str); // 7
}