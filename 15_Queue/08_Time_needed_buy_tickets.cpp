#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Time needed to by Ticket

int timeRequiredToBuy(vector<int>&tickets, int k)
{
    queue<int>q;
    int n = tickets.size();
    for(int i=0; i<n; i++)
    q.push(i);

    int time = 0;
    while(tickets[k]!=0)
    {
        tickets[q.front()]--;
        if(tickets[q.front()])
        q.push(q.front());

        q.pop();
        time++;
    }

    return time;

};

int main()
{
    vector<int>tickets = {2,3,2};
    
    int ans = timeRequiredToBuy(tickets, 2);
    cout<<ans<<endl; // 6
}