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
Node *constructBST(Node *root, int target)
{
    if(!root)
    {
        Node *root = new Node(target);
        return root;
    }

    if(root->data>target)
    root->left = constructBST(root->left, target);
    else
    root->right = constructBST(root->right, target);

    return root;

};

// T.C -> O(n)
Node *constructBST2(vector<int>&arr, int &index, int lower, int upper)
{
    if(index==arr.size() || arr[index]<lower || arr[index]>upper)
    return NULL;

    Node *root = new Node(arr[index++]);
    root->left = constructBST2(arr, index, lower, root->data);
    root->right = constructBST2(arr, index, root->data, upper);
    return root;
};

void preOrder(Node *root)
{
    if(!root)
    return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node *root = NULL;
    vector<int>arr = {8,5,1,7,10,12};

    // Create BST using preorder traversal
    // for(int i=0; i<arr.size(); i++)
    // root = constructBST1(root, arr[i]);
    
    int index = 0;
    root = constructBST2(arr, index, INT32_MIN, INT32_MAX);

    // print preOrder element
    preOrder(root); // 8 5 1 7 10 12 
}