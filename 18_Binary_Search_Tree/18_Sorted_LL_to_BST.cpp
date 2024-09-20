#include<iostream>
#include<vector>
using namespace std;

class TNode
{
    public:
    int data;
    TNode *left, *right;
    TNode(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class LNode
{
    public:
    int data;
    LNode *next;
    LNode(int value)
    {
        data = value;
        next = NULL;
    }
};

LNode* LinkedList(int arr[], int index, int size)
{
    if(index==size)
    return NULL;

    LNode *temp;
    temp = new LNode(arr[index]);
    temp->next = LinkedList(arr, index+1, size);
    return temp;
};

TNode *BuildBST(vector<int>&Tree, int start, int end)
{
    if(start>end)
    return NULL;

    int mid = start+(end-start+1)/2;
    TNode *root = new TNode(Tree[mid]);
    root->left = BuildBST(Tree, start, mid-1);
    root->right = BuildBST(Tree, mid+1, end);
    return root;
};

void PreOrder(TNode *root)
{
    if(!root)
    return;

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

TNode *sortedListToBST(LNode *head)
{
    vector<int>Tree;
    while(head)
    {
        Tree.push_back(head->data);
        head = head->next;
    }

    return BuildBST(Tree, 0, Tree.size()-1);
};


int main()
{
    LNode *head = NULL;
    int arr[] = {1,2,3,4,5,6,7};
    head = LinkedList(arr, 0, 7);

    TNode *root = NULL;
    root = sortedListToBST(head);

    PreOrder(root); // 4 2 1 3 6 5 7
}