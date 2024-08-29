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

int hight(Node *root, bool &valid)
{
    if(!root)
    return 0;

    int l = hight(root->left, valid);
    if(valid)
    {
        int r = hight(root->right, valid);

        if(abs(l-r)>1)
        valid = 0;

        return 1+max(l, r);
    }
    return -1;
};

bool isBalanced(Node *root)
{
    bool valid = 1;
    hight(root, valid);
    return valid;    
}

Node* BinaryTree()
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

    cout<<isBalanced(root);
}