#include<iostream>
using namespace std;

// Remove Nth Node from end
class Node
{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* CreateLinkedList(int arr[], int index, int size)
{
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
};

Node* remove_Nth_Node(Node *head, int x)
{
    int count=0;
    Node *temp = head;
    // Count total number of Nodes
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    count-=x;
    if(count==0)
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *pre = NULL, *curr = head;
    while(count--)
    {
        pre = curr;
        curr = curr->next;
    }
    pre->next = curr->next;
    delete curr;

    return head;
};

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,4,5};
    head = CreateLinkedList(arr, 0, 5);
    // remove Nth Node from last
    head = remove_Nth_Node(head, 1);
    // print value
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" "; // 1 2 3 5
        temp = temp->next;
    }
};