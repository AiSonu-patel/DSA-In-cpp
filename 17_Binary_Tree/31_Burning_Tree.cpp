#include <iostream>
using namespace std;

// Expected Time Complexity: O(number of nodes)
// Expected Auxiliary Space: O(height of tree)

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

void find(Node *root, int target, Node *&BurnNode)
{
    if (!root)
        return;

    if (root->data == target)
    {
        BurnNode = root;
        return;
    }

    find(root->left, target, BurnNode);
    find(root->right, target, BurnNode);
};

int hight(Node *root)
{
    if (!root)
        return 0;

    return 1 + max(hight(root->left), hight(root->right));
};

int Burn(Node *root, int &timer, int target)
{
    if (!root)
        return 0;

    if (root->data == target)
        return -1;

    int left = Burn(root->left, timer, target);
    int right = Burn(root->right, timer, target);

    if (left < 0)
    {
        timer = max(timer, abs(left) + right);
        return left - 1;
    }

    if (right < 0)
    {
        timer = max(timer, left + abs(right));
        return right - 1;
    }

    return 1 + max(left, right);
};

Node *BinaryTree()
{
    int x;
    cin>>x;
    if (x == -1)
        return NULL;

    Node *temp = new Node(x);
    cout << "Enter the left child " << x << " : ";
    temp->left = BinaryTree();

    cout << "Enter the right child " << x << " : ";
    temp->right = BinaryTree();
    return temp;
};

int main()
{
    Node *root;
    cout << "Enter the root Node : ";
    root = BinaryTree();

    int timer = 0;
    int target = 8;
    Burn(root, timer, target);

    Node *BurnNode = NULL;
    find(root, target, BurnNode);

    int high = hight(BurnNode) - 1;

    int ans = max(timer, high);
    cout<<ans;

   
}