#include<iostream>
#include <vector>
using namespace std;

void subset(int arr[], int index, int n, vector<vector<int>>&ans, vector<int>&temp)
{
    if(index==n)
    {
        ans.push_back(temp);
        return;
    }

    int sum=0;
    // No selected
    subset(arr, index+1, n, ans, temp);
    // selected
    temp.push_back(arr[index]);
    subset(arr, index+1, n, ans, temp);
    temp.pop_back();
}

int main()
{
    int arr[3] = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;

    subset(arr, 0, 3, ans, temp);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}