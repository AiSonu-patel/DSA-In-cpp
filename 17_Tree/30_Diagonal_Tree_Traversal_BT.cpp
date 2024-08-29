#include<iostream>
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

void find(Node *root, int pos, int &l)
{
    if(!root)
    return;

    l = max(pos, l);
    find(root->left, pos+1, l);
    find(root->right, pos, l);
}

void findDig(Node *root, int pos, vector<vector<int>>&ans)
{
    if(!root)
    return;

    ans[pos].push_back(root->data);
    findDig(root->left, pos+1, ans);
    findDig(root->right, pos, ans);
}

vector<int> diagonal(Node *root)
{
    int l = 0;
    find(root, 0, l);
    vector<vector<int>>ans(l+1);
    findDig(root, 0, ans);

    vector<int>temp;
    for(int i=0; i<ans.size(); i++)
    for(int j=0; j<ans[i].size(); j++)
    temp.push_back(ans[i][j]);

    return temp;
}

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

    vector<int>ans = diagonal(root);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}