#include<iostream>
#include<queue>
using namespace std;

// Level Order Traversal
// T.C -> O(n)
// S.C -> O(n);

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

void levelOrder(Node *root)
{
    queue<Node*>q;
    Node *temp;
    q.push(root);
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
    // left
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BinaryTree();
    // right
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BinaryTree();
    return temp;
}

int main()
{
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();

    // PreOrder Traversal
    levelOrder(root); // 1 2 7 3 6 8 4 5 9 10
}