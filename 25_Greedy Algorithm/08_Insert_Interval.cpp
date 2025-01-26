#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    vector<vector<int>>ans;
    int n = intervals.size();
    int i=0;
    while(i<n && newInterval[0]>intervals[i][1])
    {
        ans.push_back(intervals[i]);
        i++;
    }

    if(i==n)
    {
        ans.push_back(newInterval);
        return ans;
    }

    while(i<n && newInterval[1]>=intervals[i][0])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    ans.push_back(newInterval);

    while(i<n)
    {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
};

int main()
{
    vector<vector<int>>intervals = {{1,3},{6,9}};
    vector<int>newInterval = {2,5};

    vector<vector<int>>ans = insert(intervals, newInterval);
    for(int i=0; i<ans.size(); i++)
    for(int j=0; j<ans[0].size(); j++)
    cout<<ans[i][j]<<" "; // [[1,5],[6,9]];
}