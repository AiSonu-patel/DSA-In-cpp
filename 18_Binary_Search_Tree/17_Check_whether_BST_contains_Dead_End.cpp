#include <iostream>
#include <vector>
using namespace std;

int n1, n2;

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

bool Dead(Node *root, int lower, int upper)
{
    if(!root)
    return 0;


    if(!root->left && !root->right)
    {
        if(root->data-lower==1 && upper-root->data==1)
        return 1;
        else
        return 0;
    }

    return Dead(root->left, lower, root->data) || Dead(root->right, root->data, upper);
};

bool isDeadEnd(Node *root)
{
    return Dead(root, 0, INT32_MAX);
}

Node *BST()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;

    Node *temp = new Node(x);
    cout << "Enter the left child " << x << " : ";
    temp->left = BST();
    cout << "Enter the right child " << x << " : ";
    temp->right = BST();

    return temp;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the root Node : ";
    root = BST();
    
    cout<<isDeadEnd(root);
}