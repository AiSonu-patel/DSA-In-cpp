#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right = NULL;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};


Node *LCA(Node *root, int n1, int n2)
{
    if(!root)
    return NULL;

    if(root->data>n1 && root->data>n2)
    return LCA(root->left, n1, n2);
    else if(root->data<n1 && root->data<n2)
    return LCA(root->right, n1, n2);
    else
    return root;
};

Node *BST()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BST();
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BST();
    return temp;
};

int main()
{
    Node *root;
    cout<<"Enter the root Node : ";
    root = BST();

    int n1 = 7;
    int n2 = 8;

    Node *temp = LCA(root, n1, n2);
    cout<<temp->data<<endl;


}