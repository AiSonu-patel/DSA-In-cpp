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

void inOrder(Node *root, vector<int>&arr)
{
    if(!root)
    return;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
};

bool isBST(Node *root, vector<int>&arr)
{
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i]<=arr[i-1])
        return 0;
    }
    return 1;
};

Node *BinarySearchTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BinarySearchTree();
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BinarySearchTree();
    return temp;
};

int main()
{
    Node *root;
    cout<<"Enter the root Node : ";
    root = BinarySearchTree();
    vector<int>arr;
    inOrder(root, arr);
    cout<<isBST(root, arr); // 0

}