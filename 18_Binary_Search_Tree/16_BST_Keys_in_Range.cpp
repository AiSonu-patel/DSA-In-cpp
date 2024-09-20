#include <iostream>
#include <vector>
using namespace std;

int n1, n2;

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

void find(Node *root, vector<int>&ans)
{
    if(!root)
    return;

    if(root->data>n1 && root->data>n2)
    find(root->left, ans);
    else if(root->data<n1 && root->data<n2)
    find(root->right, ans);
    else
    {
        find(root->left, ans);
        ans.push_back(root->data);
        find(root->right, ans);
    }
};

vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int>ans;
    n1 = low, n2 = high;
    find(root, ans);
    return ans;
}

Node *BST()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;

    Node *temp = new Node(x);
    cout << "Enter the left child " << x << " : ";
    temp->left = BST();
    cout << "Enter the right child " << x << " : ";
    temp->right = BST();

    return temp;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the root Node : ";
    root = BST();
    int low = 4, high = 24;
    vector<int>ans = printNearNodes(root, low, high);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}