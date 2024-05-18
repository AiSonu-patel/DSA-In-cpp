#include<iostream>
#include <vector>
using namespace std;

// T.C -> O(n);

void subsequence(int arr[], int index, int n, vector<vector<int>>&ans, vector<int> &temp)
{
    if(index==n)
    {
        ans.push_back(temp);
        return;
    }
    // No select
    subsequence(arr, index+1, n, ans, temp);
    // Yes select
    temp.push_back(arr[index]);
    subsequence(arr, index+1, n, ans, temp);
    temp.pop_back();
}

int main()
{
    int arr[] = {1,2,3};
    int n = 3;
    vector<vector<int>> ans;
    vector<int> temp;

    subsequence(arr, 0, n, ans, temp);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;  // {},{3},{2}{2,3},{1},{1,3},{1,2},{1,2,3}
    }
}