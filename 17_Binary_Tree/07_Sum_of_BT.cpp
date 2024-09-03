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

void SumOfBT(Node *root, int &sum)
{
    if(!root)
    return;

    sum += root->data;
    // left
    SumOfBT(root->left, sum);
    // right
    SumOfBT(root->right, sum);

    
};

Node* BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BinaryTree();
    cout<<"Enter the left child "<<x<<" : ";
    temp->right = BinaryTree();
    return temp;
};

int main()
{
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();
    // sum of number of node data;
    int sum = 0;
    SumOfBT(root, sum);
    cout<<sum; // 55
}