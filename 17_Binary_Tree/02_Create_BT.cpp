#include<iostream>
using namespace std;

// Create Binary tree
// T.C -> O(n)
// S.C ->O(h) or O(n)

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

Node *BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    // left side create
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BinaryTree();
    // right side create
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BinaryTree();
    return temp;
}

int main()
{
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();
}