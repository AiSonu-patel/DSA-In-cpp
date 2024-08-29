#include<iostream>
#include<vector>
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

void find(Node *root, int pos, int &l, int &r)
{
    if(!root)
    return;

    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos-1, l, r);
    find(root->right, pos+1, l, r);

}

//Function to find the vertical order traversal of Binary Tree.
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

vector<int> verticalOrder(Node *root)
{
    int l=0, r=0;
    find(root, 0, l, r);
    vector<vector<int>>Positive(r+1);
    vector<vector<int>>Negative(abs(l)+1);

    queue<Node*>q;
    queue<int>index;
    q.push(root);
    index.push(0);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if(pos>=0)
        Positive[pos].push_back(temp->data);
        else
        Negative[abs(pos)].push_back(temp->data);

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
    vector<int>ans;
    for(int i=Negative.size()-1; i>0; i--)
    for(int j=0; j<Negative[i].size(); j++)
    ans.push_back(Negative[i][j]);

    for(int i=0; i<Positive.size(); i++)
    for(int j=0; j<Positive[i].size(); j++)
    ans.push_back(Positive[i][j]);

    return ans;
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
    Node *root;
    cout<<"Enter the root Node : ";
    root = BinaryTree();

    vector<int>ans = verticalOrder(root);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}