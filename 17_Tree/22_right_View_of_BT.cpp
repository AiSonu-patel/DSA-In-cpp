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

vector<int> rightView(Node *root)
{
   // Your code here
   vector<int>ans;
   if(!root)
   return ans;
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty())
   {
       ans.push_back(q.front()->data);
       int n = q.size();
       while(n--)
       {
           Node *temp = q.front();
           q.pop();
           if(temp->right)
           q.push(temp->right);
           if(temp->left)
           q.push(temp->left);
       }
   }
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

    vector<int>ans = rightView(root);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";

}