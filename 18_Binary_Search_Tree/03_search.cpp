#include<iostream>
using namespace std;

// Expected Time Complexity: O(Height of the BST)
// Expected Auxiliary Space: O(1)

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

// Function to search a node in BST.
bool Search(Node *root, int x) {
    // Your code here
    if(!root)
    return 0;
    
    if(root->data == x)
    return 1;
    
    if(root->data>x)
    return Search(root->left, x);
    else
    return Search(root->right, x);
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

    cout<<Search(root, 87); // 1
}