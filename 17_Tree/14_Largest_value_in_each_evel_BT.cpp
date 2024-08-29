#include<iostream>
#include <vector>
#include <queue>
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

vector<int> largestValues(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    Node *temp;
    while(!q.empty())
    {
        int n = q.size();
        int maxi = 0;
        for(int i=0; i<n; i++)
        {
            temp = q.front();
            q.pop();
            maxi = max(temp->data, maxi);

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
        ans.push_back(maxi);
    }
    return ans;
};

Node *BinaryTree()
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
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();
    
    vector<int> ans1;
    ans1 = largestValues(root); 
    for(int i=0; i<ans1.size(); i++)
    cout<<ans1[i]<<" "; // 1 3 7 12 14 15
}