#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Function to return a list of nodes visible from the top view
// T.C -> O(n);
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

void find(Node *root, int pos, int &l, int &r)
{
    if(!root)
    return;

    l = min(pos, l);
    r = max(pos, r);

    find(root->left, pos-1, l, r);
    find(root->right, pos+1, l, r);
};

vector<int> topView(Node *root)
{
    int l=0, r=0;
    find(root, 0, l, r);

    vector<int>ans(r-l+1);
    vector<bool>filled(r-l+1, 0);

    queue<Node*>q;
    queue<int>index;
    q.push(root);
    index.push(-1*l);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if(!filled[pos])
        {
            filled[pos] = 1;
            ans[pos] = temp->data;
        }

        if(temp->left)
        {
            q.push(temp->left);
            index.push(pos-1);
        }

        if(temp->right)
        {
            q.push(temp->right);
            index.push(pos+1);
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
}

int main()
{
    cout<<"Enter the root Node : ";
    Node *root;
    root = BinaryTree();

    vector<int> ans = topView(root);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";

}