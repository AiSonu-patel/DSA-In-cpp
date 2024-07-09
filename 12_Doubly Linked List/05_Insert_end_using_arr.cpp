#include<iostream>
using namespace std;
// Insert at end using arr withouth trav

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
    Node *head, *tail;
    tail = head = NULL;
    int arr[] = {1,2,3,4};

    for(int i=0; i<4; i++)
    {
        // LinkedList doesn't exist
        if(head==NULL)
        {
            head = new Node(arr[i]);
            tail = head;
        }
        // Already exist
        else
        {
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;          
        }
    }

    // print value
    Node *trav = head;
    while(trav)
    {
        cout<<trav->data<<" "; // 1 2 3 4 
        trav=trav->next;
    }
}