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

int countLeaf(Node *root)
{
    if(root==NULL)
    return 0;

    if(!root->left && !root->right)
    return 1;

    return (countLeaf(root->left)+countLeaf(root->right));
}

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
    cout<<"Enter the root element : ";
    Node *root;
    root = BinaryTree();

    // count leaf Node
    cout<<countLeaf(root); // 5
}