#include<iostream>
using namespace std;
// Create Circular Linked List using array
class Node
{
    public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int arr[] = {1,2,3,4,5};

    for(int i=0; i<5; i++)
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
            tail = temp;
            tail->next = head;
        }
    }

    //print value
    Node *temp = head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!=head);
}