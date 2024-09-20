#include<iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int n)
    {
        data = n;
        left = right = NULL;
    }
};

void KSmallest(Node *root, int &ans, int &k)
{
    if(!root)
    return;

    // inOrder traversal (LNR)
    KSmallest(root->left, ans, k);
    k--;
    if(k==0)
    ans = root->data;

    if(k<=0)
    return;

    KSmallest(root->right, ans, k);
}

int kthSmallest(Node *root, int k)
{
    int ans = 0;
    KSmallest(root, ans, k);
    return ans;
};

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
    Node *root;
    cout<<"Enter the root Node : ";
    root = BinarySearchTree();

    cout<<kthSmallest(root, 2);
}