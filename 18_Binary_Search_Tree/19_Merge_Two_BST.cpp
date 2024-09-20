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

void inOrder(Node *root, vector<int>&ans)
{
    if(root==NULL)
    return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

vector<int> mergeTwoBST(Node *root1, Node *root2)
{
    vector<int>ans1;
    vector<int>ans2;
    inOrder(root1, ans1);
    inOrder(root2, ans2);

    int i=0, j=0;
    vector<int>ans;
    while(i<ans1.size() && j<ans2.size())
    {
        if(ans1[i]<ans2[j])
        ans.push_back(ans1[i++]);
        else
        ans.push_back(ans2[j++]);
    }

    while(i<ans1.size())
    {
        ans.push_back(ans1[i++]);
    }

    while(j<ans2.size())
    {
        ans.push_back(ans2[j++]);
    }

    return ans;
};

Node *BST()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    cout<<"Enter the left child "<<x<<" : ";
    temp->left = BST();
    cout<<"Enter the right child "<<x<<" : ";
    temp->right = BST();

    return temp;
}

int main()
{
    Node *root1 = NULL;
    cout<<"Enter the root1 Node : ";
    root1 = BST();

    Node *root2 = NULL;
    cout<<"Enter the root2 Node : ";
    root2 = BST();

    vector<int>ans = mergeTwoBST(root1, root2);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";

}