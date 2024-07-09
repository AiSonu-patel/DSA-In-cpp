#include<iostream>
using namespace std;

// Delete st start Node
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }
};

Node* CreateDLL(Node *head, int arr[], int size)
{
    Node *tail = NULL;
    for(int i=0; i<size; i++)
    {
        if(head == NULL)
        {
            head = new Node(arr[i]);
            tail = head;
        }
        else
        {
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    return head;
};

Node* Delete_at_start(Node *head)
{
    if(head != NULL)
    {
        if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return head;
};

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,4,5};
    head = CreateDLL(NULL, arr, 5);
    // delete at start
    head = Delete_at_start(head);
    
    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 2 3 4 5
        temp = temp->next;
    }
}