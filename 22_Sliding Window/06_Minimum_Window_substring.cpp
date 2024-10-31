#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity O()
// Space Complexity O()
string minSubStringLen(string s, string t)
{
    int total = t.size();
    // unordered_map<char, int>m;
    vector<int>m(256,0);
    for(int i=0; i<t.size(); i++)
    m[t[i]]++;

    int start=0, end=0, ans=INT_MAX, index=-1;
    // ans => minimum length of substring
    // index => starting index our answer
    while(end<s.size())
    {
        m[s[end]]--; // decrease the count of char
        if(m[s[end]]>=0) // if count is not negative
        total--; // decrease the total

        // can we decrease the size of window
        while(!total&&start<=end)
        {
            // update the length of substring
            if(ans>end-start+1)
            {
                ans = end-start+1;
                index=start;
            }

            m[s[start]]++; // increase the count of char
            if(m[s[start]]>0) // if count is positive
            total++; // increase the total

            start++; // move the start, decrease the size
        }

        // Increase the size of window
        end++;
    }

    if(index==-1)
    return "";

    string str = "";
    for(int i=index; i<index+ans; i++)
    {
        str+=s[i];
    }

    return str;
};

int main()
{
    string s = "ADOBECODEBANC"; // t="ABC", out="BANC"
    // string s = "a"; // t="a", out="a"
    // string s = "a"; // t="aa", out=""

    string t = "ABC";
    cout<<minSubStringLen(s, t);
}