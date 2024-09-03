#include<iostream>
#include<queue>
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

bool parent(Node *root, int a, int b)
{
    if(!root)
    return 0;
    
    if(root->left && root->right)
    {
        if(root->left->data==a && root->right->data==b)
        return 1;
        if(root->left->data==b && root->right->data==a)
        return 1;
    }
    
    return parent(root->left, a, b)||parent(root->right, a, b);
}
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b) {
    // add code here.
    if(!root->left && !root->right)
    return 0;
    
    queue<Node*>q;
    q.push(root);
    int l1=-1, l2=-1;
    int level = 0;
    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            Node *temp = q.front();
            q.pop();
            if(temp->data==a)
            l1 = level;
            if(temp->data==b)
            l2 = level;
            
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        level++;
        
        if(l1!=l2)
        return 0;
        
        if(l1!=-1)
        break;
    }
    return !parent(root, a, b);
}

Node* BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BinaryTree();
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BinaryTree();
    return temp;
};

int main()
{
    Node *root;
    cout<<"Enter the root Node : ";
    root = BinaryTree();

    cout<<isCousins(root, 5, 4);


}