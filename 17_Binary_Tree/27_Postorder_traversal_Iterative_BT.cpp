#include<iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
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

vector<int> PostOrder(Node *root)
{
    stack<Node*>st;
    st.push(root);
    vector<int>ans;
    Node *temp;

    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        ans.push_back(temp->data);

        if(temp->left)
        st.push(temp->left);

        if(temp->right)
        st.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
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

    vector<int>ans = PostOrder(root);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}