#include<iostream>
#include<vector>
#include<stack>
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

vector<int> InOrder(Node *root)
{
    stack<Node*>st;
    stack<bool>visited;
    st.push(root);
    visited.push(0);
    vector<int>ans;
    Node *temp;
    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        bool flage = visited.top();
        visited.pop();

        if(flage==0)
        {
            if(temp->right)
            {
                st.push(temp->right);
                visited.push(0);
            }

            st.push(temp);
            visited.push(1);

            if(temp->left)
            {
                st.push(temp->left);
                visited.push(0);
            }
        }
        else
        ans.push_back(temp->data); 
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
}

int main()
{
    Node *root;
    cout<<"Enter the root Node : ";
    root = BinaryTree();

    vector<int>ans = InOrder(root);
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
}