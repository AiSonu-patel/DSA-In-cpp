#include<iostream>
using namespace std;

// T.C -> O(n)
// S.C -> 

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

Node *deleteNode(Node * &root, int target)
{
    if(!root)
    return NULL;

    if(root->data>target)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }
    else if(root->data<target)
    {
        root->right = deleteNode(root->right, target);
        return root;
    }
    else
    {
        if(!root->left && root->right)
        {
            delete root;
            return NULL;
        }
        else if(!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *child = root->left;
            Node *parent = root;

            while(child->right)
            {
                parent = child;
                child = child->right;
            }

            if(root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
};

void inOrder(Node *root)
{
    if(!root)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
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

    int target = 9;
    deleteNode(root, target);

    // print elements
    inOrder(root); // 1 2 4 5 7 8 11 12
}