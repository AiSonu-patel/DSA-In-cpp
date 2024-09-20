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

void MinDist(Node *root, int &prev, int &ans)
{
    if(!root)
    return;

    MinDist(root->left, prev, ans);
    if(prev != INT32_MIN)
    ans = min(ans, root->data-prev);
    prev = root->data;
    MinDist(root->right, prev, ans);

};

int MinDistBetweenBSTNode(Node *root)
{
    int prev = INT32_MIN;
    int ans = INT32_MAX;
    MinDist(root, prev, ans);
    return ans;
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

}

int main()
{
    Node *root = NULL;
    cout<<"Enter the root Node : ";
    root = BinarySearchTree();

    cout<<MinDistBetweenBSTNode(root);
}