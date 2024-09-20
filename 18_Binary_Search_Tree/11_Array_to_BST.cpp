#include<iostream>
#include <vector>
using namespace std;

void sortedArrayToBST(vector<int>&arr, int start, int end, vector<int>&ans)
{
    if(start>end)
    return;

    int mid = start+(end-start)/2;
    ans.push_back(arr[mid]);
    sortedArrayToBST(arr, start, mid-1, ans);
    sortedArrayToBST(arr, mid+1, end, ans);
}

int main()
{
    vector<int>arr = {1,2,3,4};
    vector<int>ans;
    sortedArrayToBST(arr, 0, arr.size()-1, ans);

    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";

}