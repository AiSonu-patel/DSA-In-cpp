#include<iostream>
#include<vector>
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

// T.C -> O(n^2)
Node *constructBST1(Node *root, int target)
{
    if(!root)
    {
        Node *root = new Node(target);
        return root;
    }
    
    if(root->data<target)
    root->right = constructBST1(root->right, target);
    else
    root->left = constructBST1(root->left, target);
    return root;
};

// T.C -> O(n)
Node *constructBST2(vector<int>&arr, int &index, int lower, int upper)
{
    if(index<0 || arr[index]<lower || arr[index]>upper)
    return NULL;

    Node *root = new Node(arr[index--]);
    root->right = constructBST2(arr, index, root->data, upper);
    root->left = constructBST2(arr, index, lower, root->data);
    return root;
};

void postOrder(Node *root)
{
    if(!root)
    return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
};

int main()
{
    vector<int>arr = {1,7,5,50,40,10};
    int n = arr.size()-1;
    Node *root = NULL;
    // for(int i=arr.size()-1; i>=0; i--)
    // root = constructBST1(root, arr[i]);

    root = constructBST2(arr, n, INT32_MIN, INT32_MAX);

    // postOrder Traversal
    postOrder(root); // 1 7 5 50 40 10
}