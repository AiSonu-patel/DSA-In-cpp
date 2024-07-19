#include<iostream>
using namespace std;
// Create Circular Linked List
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
    
    if(head == NULL)
    {
        head = new Node(5);
        head->next = head;
    }
    else
    {
        Node *tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        Node *temp = new Node(10);
        tail->next = temp;
        tail = temp;
        tail->next = head;

    }

    //print value
    Node *temp = head;
    do
    {
        cout<<temp->data<<"->"; // 5->
        temp=temp->next;
    }
    while(temp!=head);
}