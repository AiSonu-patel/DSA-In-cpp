#include<iostream>
using namespace std;
// Insert at end

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

int main()
{
    // Insert at end
    Node *head = NULL;

    // LinkedList doesn't exist
    if(head==NULL)
    {
        head = new Node(5);
    }
    // Already exist
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    Node *temp = new Node(10);
    curr->next = temp;
    temp->prev = curr;

    // print value
    Node *trav = head;
    while(trav)
    {
        cout<<trav->data<<" "; // 5 10 
        trav=trav->next;
    }
}