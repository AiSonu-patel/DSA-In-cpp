#include<iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *solve(int start, int end, vector<int>&nums)
{
    if(start>end)
    return NULL;

    if(start==end)
    return new Node(nums[start]);

    int mid = start+(end-start)/2;

    Node *newNode = new Node(nums[mid]);
    newNode->left = solve(start, mid-1, nums);
    newNode->right = solve(mid+1, end, nums);
    return newNode;
};

Node *sortedArrayToBST(vector<int>&nums)
{
    return solve(0, nums.size()-1, nums);
};

int hight(Node *root)
{
    if(!root)
    return 0;
    
    return 1 + max(hight(root->left),hight(root->right));
};

int main()
{
    Node *root = NULL;
    vector<int>nums = {1,2,3,4,5,6,7};
    root = sortedArrayToBST(nums);

    cout<<hight(root); // 3
}