#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> minPartition(int N)
{
    int currency[] = {2000,500,200,100,50,20,10,5,2,1};
    int notes = 0, i = 0;
    vector<int>ans;
    while(N)
    {
        notes = N/currency[i];
        while(notes--)
        {
            ans.push_back(currency[i]);
        }

        N%=currency[i];
        i++;
    }
    return ans;
};

int main()
{
    int N = 143;
    vector<int>ans = minPartition(N);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" "; // 100 20 20 2 1
}