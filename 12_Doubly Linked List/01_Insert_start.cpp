#include<iostream>
using namespace std;
// Insert at start
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node *head = NULL;
        // Linked list doesn't exist
        if(head==NULL)
        {
            head = new Node(5);
        }
        // Already exist
        else
        {
            Node *temp = new Node(10);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

    // print value
    Node *trav = head;
    while(trav)
    {
        cout<<trav->data<<" "; // 5
        trav=trav->next;
    }
}