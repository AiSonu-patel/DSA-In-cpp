#include<iostream>
#include <vector>
using namespace std;

// T.C -> O(n)

void subseq(string &str, int index, int n, vector<string>&ans, string &temp)
{
    if(index==n)
    {
        ans.push_back(temp);
        return;
    }

    // Not included
    subseq(str, index+1, n, ans, temp);
    // Included
    temp.push_back(str[index]);
    subseq(str, index+1, n, ans, temp);
    temp.pop_back();
}

int main()
{
    string str = "abc";
    vector<string> ans;
    string temp;

    subseq(str, 0, str.size(), ans, temp);

    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<endl; // {}, {c}, {b}, {bc}, {a}, {ac}, {ab}, {abc}
}