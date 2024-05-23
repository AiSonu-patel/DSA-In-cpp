#include<iostream>
#include <vector>
using namespace std;

// T.C -> O(n*n!)
// S.C -> (n)

void permut(int arr[], vector<vector<int>>&ans, vector<int>&temp, vector<bool>&visit)
{
    if(visit.size()==temp.size())
    {
        ans.push_back(temp);
        return;
    }

    for(int i=0; i<visit.size(); i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            temp.push_back(arr[i]);
            permut(arr, ans, temp, visit);
            visit[i]=0;
            temp.pop_back();
        }
    }
}

// without extra space using
void permut2(vector<int>&arr, vector<vector<int> > &ans, int index)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for(int i=index; i<arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        permut2(arr, ans, index+1);
        swap(arr[i], arr[index]);
    }
}

int main()
{
    // int arr[] = {1,2,3};
    // vector<vector<int>> ans;
    // vector<int> temp;
    // vector<bool> visit(3, 0);

    // permut(arr, ans, temp, visit);
    // for(int i=0; i<ans.size(); i++)
    // {
    //     for(int j=0; j<ans[i].size(); j++)
    //     cout<<ans[i][j]<<" ";
    //     cout<<endl; // {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}
    // }

    vector<int> arr1 = {1,2,3};
    vector<vector<int>> ans1;
    int index=0;
    permut2(arr1, ans1, index);

    for(int i=0; i<ans1.size(); i++)
    {
        for(int j=0; j<ans1[i].size(); j++)
        cout<<ans1[i][j]<<" ";
        cout<<endl; // {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}
    }
}