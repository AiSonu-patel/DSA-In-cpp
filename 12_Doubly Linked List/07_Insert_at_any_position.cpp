#include<iostream>
using namespace std;

// Insert at any given position
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

Node *CreateDLL(int arr[], int index, int size, Node *back)
{
    if(index==size)
    return NULL;
    Node *temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = CreateDLL(arr, index+1, size, temp);
    return temp;
}

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,4,5};
    head = CreateDLL(arr, 0, 5, NULL);

    // Insert at given position
    int poss = 2;
    // isert at start
    if(poss==0)
    {
        // LinkedList exist na kare
        if(head==NULL)
        {
            head = new Node(5);
        }
        // exist karti
        else
        {
            Node *temp = new Node(5);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else
    {
        Node *curr = head;
        // Go to the node, after which I have to insert
        while(--poss)
        {
            curr = curr->next;
        }
        // insert at end
        if(curr->next==NULL) // Last Node
        {
            Node *temp = new Node(5);
            curr->next = temp;
            temp->prev = curr;
        }
        // Insert at middle
        else
        {
            Node *temp = new Node(5);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
        }
    }

    Node *trav = head;
    while(trav)
    {
        cout<<trav->data<<" "; // 1 2 5 3 4 5
        trav = trav->next;
    }
}