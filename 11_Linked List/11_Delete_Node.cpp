#include<iostream>
using namespace std;

// Delete a Node at particular index using recursion
class Node
{
    public:
    int data;
    Node *next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

Node* CreateLinkedList(int arr[], int index, int size)
{
    // base case
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
}

Node* deleteNode(Node *curr, int x)
{
    // base case
    if(x==1)
    {
        Node *temp = curr->next;
        delete curr;
        return temp;
    }
    curr->next = deleteNode(curr->next, x-1);
    return curr;
}

int main()
{
    Node *head;
    head=NULL;
    int arr[] = {1,2,3,4,5};
    head = CreateLinkedList(arr, 0, 5); 
    head = deleteNode(head, 1);
    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 2 3 4 5
        temp = temp->next;
    }
}