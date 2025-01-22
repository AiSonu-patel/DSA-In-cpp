#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool comp(pair<int,int>a, pair<int,int>b)
{
    return a.second<b.second;
};

// Time Complexity: O(n log n)
// Auxiliary Space: O(n)

int maxMeetings(vector<int>& start, vector<int>& end) 
{
    // sort it on the basis of end time in ascending order
    int n = start.size();
    vector<pair<int, int>>timer;
    for(int i=0; i<n; i++)
    timer.push_back({start[i], end[i]});

    sort(timer.begin(), timer.end(), comp);

    int total = 0; // maximum kitni meeting karwa sakta hu
    int ending = -1;
    for(int i=0; i<n; i++)
    {
        if(timer[i].first>ending)
        {
            total++;
            ending = timer[i].second;
        }
    }

    // previous meeting end time should be less than starting time of next meeting

    return total;
}

int main()
{
    vector<int>start = {1,3,0,5,8,5};
    vector<int>end = {2,4,6,7,9,9};
    cout<<maxMeetings(start, end); // 4
}