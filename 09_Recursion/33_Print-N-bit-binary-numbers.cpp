#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(int n, vector<string>&ans, int zero, int one, string &temp)
{
    if(temp.size()==n)
    {
        ans.push_back(temp);
        return;
    }

    if(zero<one)
    {
        temp.push_back('0');
        find(n, ans, zero+1, one, temp);
        temp.pop_back();
    }
    temp.push_back('1');
    find(n, ans, zero, one+1, temp);
    temp.pop_back();
}

int main()
{
    int n=3;
    vector<string>ans;
    string temp;
    find(n, ans, 0, 0, temp);
    sort(ans.begin(), ans.end(), greater<>());
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";  // 1010 1011 1100 1101 1110 1111
    cout<<endl;
}