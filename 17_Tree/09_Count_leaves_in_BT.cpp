#include<iostream>
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

void countLeaves(Node *root, int &count)
{
    if(root==NULL)
    return;

    if(!root->left && !root->right)
    {
        count++;
        return;
    }
    countLeaves(root->left, count);
    countLeaves(root->right, count);
};

Node *BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BinaryTree();
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BinaryTree();
    return temp;
};

int main()
{
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();

    int count = 0;
    countLeaves(root, count);
    cout<<count; // 5
}