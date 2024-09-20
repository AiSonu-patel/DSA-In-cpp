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

Node *Insert(Node *root, int target)
{
    if(!root)
    {
        Node *root = new Node(target);
        return root;
    }

    if(root->data>target)
    root->left = Insert(root->left, target);
    else
    root->right = Insert(root->right, target);

    return root;
};

void inOrder(Node *root)
{
    if(!root)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
};

bool search(Node *root, int target)
{
    if(!root)
    return 0;

    if(root->data == target)
    return 1;

    if(root->data>target)
    return search(root->left, target);
    else
    return search(root->right, target);
}

int main()
{
    int arr[] = {6,3,11,5,7,18,12,2};

    Node *root = NULL;
    for(int i=0; i<8; i++)
    root = Insert(root, arr[i]);

    // search element
    cout<<search(root, 11)<<endl; // 1

    // print value inOrder
    // inOrder(root); // 2 3 5 6 7 11 12 18
}