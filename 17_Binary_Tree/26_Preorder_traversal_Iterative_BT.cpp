#include<iostream>
#include<stack>
#include <vector>
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

// Given a Binary tree. Find the preorder traversal of the tree without using recursion.
vector<int> PreOrder(Node *root) // NLR
{
    stack<Node*>st;
    st.push(root);
    vector<int>ans;
    while(!st.empty())
    {
        Node * temp = st.top();
        st.pop();
        ans.push_back(temp->data);

        if(temp->right)
        st.push(temp->right);

        if(temp->left)
        st.push(temp->left);

    }
    return ans;
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
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BinaryTree();
    return temp;
};

int main()
{
    Node *root;
    cout<<"Enter the root Node : ";
    root = BinaryTree();

    vector<int>ans = PreOrder(root);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}