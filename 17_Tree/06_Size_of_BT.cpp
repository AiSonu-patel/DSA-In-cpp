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

int TotalNode(Node *root)
{
    if(root==NULL)
    return 0;

    return (1+TotalNode(root->left)+TotalNode(root->right));
}

Node* BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left child "<<x<<": ";
    temp->left = BinaryTree();
    cout<<"Enter the right child "<<x<<": ";
    temp->right = BinaryTree();
    return temp;
}

int main()
{
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();

    // Count Number of Node
    int n = TotalNode(root);
    cout<<n<<endl; // 10
}