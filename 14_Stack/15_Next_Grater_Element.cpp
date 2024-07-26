#include<iostream>
#include<vector>
using namespace std;

// T.C -> O(n^2)
// S.C -> O(1)

vector<int> nextGraterElement(vector<int> arr, int n)
{
    vector<int>ans (n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]>arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
    
}

int main()
{
    vector<int>arr = {6,8,0,1,3};

    arr = nextGraterElement(arr,arr.size());

    //print value
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" "; // 8 -1 1 3 -1
    }
}