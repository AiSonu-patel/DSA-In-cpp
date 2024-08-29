#include<iostream>
#include<queue>
using namespace std;

// T.C -> O(n)
// S.C -> O(h) or O(n)

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

// Pre-order traversal (NLR)
void PreOrder(Node *root)
{
    if(root==NULL)
    return;

    // Node
    cout<<root->data<<" ";
    // left
    PreOrder(root->left);
    // right
    PreOrder(root->right);
}

// In-order traversal (LNR)
void InOrder(Node *root)
{
    if(root==NULL)
    return;

    // Left
    InOrder(root->left);
    // Node
    cout<<root->data<<" ";
    // Right
    InOrder(root->right);
};

// PostOrder traversal (LRN)
void PostOrder(Node *root)
{
    if(root==NULL)
    return;

    // Left
    PostOrder(root->left);
    // Right
    PostOrder(root->right);
    // Node
    cout<<root->data<<" ";
}

// Level Order Traversal
void levelOrder(Node *root)
{
    queue<Node*>q;
    q.push(root);
    Node *temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right);
    }
}

Node* BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    // left side create
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BinaryTree();
    // right side create
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BinaryTree();
    
};

int main()
{
    // tree create
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();

    // print pre-order
    cout<<"Pre-order: "; // Pre-order: 1 2 3 4 5 6 7 8 9 10
    PreOrder(root);

    // print in-order
    cout<<"\nIn-order: "; // In-order: 4 3 5 2 6 1 7 9 8 10
    InOrder(root); 

    // print post-order
    cout<<"\nPost-order: "; // Post-order: 4 5 3 6 2 9 10 8 7 1
    PostOrder(root);

    // print Level Order Traversal
    cout<<"\nLevel-order: "; // Level-order: 1 2 7 3 6 8 4 5 9 10
    levelOrder(root);
}