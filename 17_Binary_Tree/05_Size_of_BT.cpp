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

void SizeOfBT(Node *root, int &count)
{
    if(root==NULL)
    return;

    count++;
    SizeOfBT(root->left, count);
    SizeOfBT(root->right, count);
}

Node * BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    // left
    cout<<"Enter the Left child "<<x<<" : ";
    temp->left = BinaryTree();
    // right
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BinaryTree();
}

int main()
{
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();

    int count = 0;
    SizeOfBT(root, count); 
    cout<<count<<endl; // 10 of size BT
}