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

bool isIdentical(Node *r1, Node *r2)
{
    if(!r1 && !r2)
    return 1;

    if((!r1 && r2) || (r1 && !r2))
    return 0;

    if(r1->data != r2->data)
    return 0;

    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
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
    Node *r1, *r2;
    cout<<"Enter the r1 Node : ";
    r1 = BinaryTree();
    cout<<"Enter the r2 Node : ";
    r2 = BinaryTree();
    
    cout<<isIdentical(r1, r2);
}