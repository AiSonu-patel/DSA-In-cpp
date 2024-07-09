#include<iostream>
using namespace std;
// Insert at end using arr


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
    int arr[] = {1,2,3,4};

    for(int i=0; i<4; i++)
    {
        // LinkedList doesn't exist
        if(head==NULL)
        {
            head = new Node(arr[i]);
        }
        // Already exist
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

    // print value
    Node *trav = head;
    while(trav)
    {
        cout<<trav->data<<" "; // 1 2 3 4 
        trav=trav->next;
    }
}