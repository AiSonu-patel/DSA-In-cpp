#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>a, vector<int>b)
{
    return a[1]<b[1];
};

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), comp);
    int end = INT_MIN;
    int remove = 0;
    for(int i=0; i<n; i++)
    {
        if(end<=intervals[i][0])
        {
            end = intervals[i][0];
        }
        else
        remove++;
    }

    return remove;
};

int main()
{
    vector<vector<int>>intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout<<eraseOverlapIntervals(intervals); // 1
}