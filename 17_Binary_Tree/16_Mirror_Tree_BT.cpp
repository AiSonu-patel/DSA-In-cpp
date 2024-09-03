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

void mirror(Node *root)
{
    if(!root)
    return;

    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;

    mirror(root->left);
    mirror(root->right);
};

void PreOrder(Node *root)
{
    if(!root)
    return;

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
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
    Node *root;
    cout<<"Enter the root Node : ";
    root = BinaryTree();

    mirror(root);
    PreOrder(root); // 1 3 2
}