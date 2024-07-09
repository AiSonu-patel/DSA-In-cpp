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
    for(int i=0; i<size; i++)
    {
        if(head == NULL)
        {
            head = new Node(arr[i]);
        }
        else
        {
            Node *curr = head;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            Node *temp = new Node(arr[i]);
            curr->next = temp;
            temp->prev = curr;
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
    if(head!=NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        if(head)
        head->prev = NULL;
    }

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 2 3 4 5
        temp = temp->next;
    }
}