#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> getOrder(vector<vector<int>>& tasks)
{
    vector<int>ans;
    int n = tasks.size();
    for(int i=0; i<n; i++)
    tasks[i].push_back(i);

    // sort the task on the basis of enqueue time
    sort(tasks.begin(), tasks.end());
    long long timer = tasks[0][0];
    int i = 0;

    //     processing timer, index
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    // put all the task into min heap whose enqueue time less than or equal to timer
    while(!pq.empty() || i<n)
    {
        while(i<n && timer>=tasks[i][0])
        {
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }

        // if min heap is empty
        if(pq.empty())
        timer = tasks[i][0];
        // not empty
        else
        {
            ans.push_back(pq.top().second);
            timer += pq.top().first;
            pq.pop();
        }
    }

    return ans;

}

int main()
{
    vector<vector<int>>tasks = {{1,2},{2,4},{3,2},{4,1}};
    vector<int>ans = getOrder(tasks);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" "; // [0,2,3,1]
}