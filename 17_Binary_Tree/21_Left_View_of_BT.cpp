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

void Lview(Node *root, int level, vector<int>&ans)
{
    if(!root)
    return;
    
    if(level==ans.size())
    ans.push_back(root->data);
    
    Lview(root->left, level+1, ans);
    Lview(root->right, level+1, ans);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   if(!root)
   return ans;
   
   Lview(root, 0, ans);
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

    vector<int>ans = leftView(root);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";

}