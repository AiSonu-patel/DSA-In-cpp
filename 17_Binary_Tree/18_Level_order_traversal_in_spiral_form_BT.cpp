#include<iostream>
#include<stack>
#include<vector>
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

vector<int> findSpiral(Node *root)
{
    stack<Node*>s1; // R to L
    stack<Node*>s2; // L to R
    vector<int>ans;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        if(!s1.empty())
        {
            while(!s1.empty())
            {
                Node *temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);

                if(temp->right)
                s2.push(temp->right);

                if(temp->left)
                s2.push(temp->left);
            }
        }
        else
        {
            while(!s2.empty())
            {
                Node *temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);

                if(temp->left)
                s1.push(temp->left);

                if(temp->right)
                s1.push(temp->right);
            }
        }
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

    vector<int>ans1 = findSpiral(root);

    for(int i=0; i<ans1.size(); i++)
    cout<<ans1[i]<<" ";


}