#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};

void KLargest(Node *root, int &ans, int &k)
{
    if(!root)
    return;

    // RNL
    KLargest(root->right, ans, k);
    k--;
    if(k==0)
    ans = root->data;

    if(k<=0)
    return;

    KLargest(root->left, ans, k);
};

// return the Kth largest element in the given BST rooted at 'root'
int kthLargest(Node *root, int k)
{
    int ans = 0;
    KLargest(root, ans, k);
    return ans;
}

Node *BinaryTreeSearch()
{
    int n;
    cin>>n;
    if(n==-1)
    return NULL;

    Node *temp = new Node(n);
    cout<<"Enter the left child "<<n<<" : ";
    temp->left = BinaryTreeSearch();
    cout<<"Enter the right child "<<n<<" : ";
    temp->right = BinaryTreeSearch();
    return temp;
};

int main()
{
    Node *root;
    cout<<"Enter the root Node : ";
    root = BinaryTreeSearch();

    cout<<kthLargest(root, 2);
}