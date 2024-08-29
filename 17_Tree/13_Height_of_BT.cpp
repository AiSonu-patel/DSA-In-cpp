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

int heightBT(Node *root)
{
    if(root==NULL)
    return 0;
    
    return (1+max(heightBT(root->left), heightBT(root->right)));
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
    
    cout<<heightBT(root); // 6
}