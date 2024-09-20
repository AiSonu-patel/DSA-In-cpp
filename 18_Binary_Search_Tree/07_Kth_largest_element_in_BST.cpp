#include<iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void inOrder(Node *root, vector<int>&arr)
{
    if(root==NULL)
    return;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);

};

int kthLargest(Node *root, int k)
{
    vector<int>arr;
    inOrder(root, arr);

    int n = arr.size();
    return arr[n-k];
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
    Node *root = NULL;
    cout<<"Enter the root Node : ";
    root = BinarySearchTree();

    cout<<kthLargest(root, 1);
}