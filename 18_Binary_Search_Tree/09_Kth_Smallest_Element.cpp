#include<iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int n)
    {
        data = n;
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

int kthSmallest(Node *root, int k)
{
    vector<int>arr;
    inOrder(root, arr);
    return arr[k-1];
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

    cout<<kthSmallest(root, 2);
}