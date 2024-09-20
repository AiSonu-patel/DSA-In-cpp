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

void KSum(Node *root, int &sum, int &k)
{
    if(!root)
    return;

    KSum(root->left, sum, k);
    k--;
    if(k>=0)
    sum+=root->data;
    if(k<=0)
    return;
    KSum(root->right, sum, k);
}

int sum(Node *root, int k)
{
    int sum = 0;
    KSum(root, sum, k);
    return sum;
}

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

    cout<<sum(root, 3);
}