#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n)
{
    // calculate the frequency of each char
    vector<int>freq(26,0);
    // count is highest freq char
    int count = 0;

    for(int i=0; i<tasks.size(); i++)
    {
        freq[tasks[i]-'A']++;
        count = max(count, freq[tasks[i]-'A']);
    }

    int ans = (count-1)*(n+1);

    for(int i=0; i<26; i++)
    {
        if(freq[i] == count)
        ans++;
    }

    return ans>tasks.size() ? ans : tasks.size();
}

int main()
{
    vector<char>tasks = {'A','A','A','B','B','B'};
    int n = 2;

    cout<<leastInterval(tasks, n); // 8

}