#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int n, int K)
{
    vector<int> adj[K];
    vector<int> InDeg(K, 0);

    for (int i = 0; i < n - 1; i++)
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0;
        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
            j++, k++;

        if (j == str1.size())
            continue;

        adj[str1[j] - 'a'].push_back(str2[k] - 'a');
        InDeg[str2[k] - 'a']++;
    }

    queue<int> q;
    for (int i = 0; i < K; i++)
        if (!InDeg[i])
            q.push(i);
    string ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        char c = 'a' + node;
        ans += c;

        for (int j = 0; j < adj[node].size(); j++)
        {
            InDeg[adj[node][j]]--;
            if (!InDeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    return ans;
};

int main()
{
    string dict[] = {"baa","abcd","abca","cab","cad"};
    cout<<findOrder(dict, 5, 4); // bdac
}