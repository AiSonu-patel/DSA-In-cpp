#include<iostream>
using namespace std;
// Insert at start using array
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
    int arr[] = {1,2,3,4};
    for(int i=0; i<4; i++)
    {
        // Linked list doesn't exist
        if(head==NULL)
        {
            head = new Node(arr[i]);
        }
        // Already exist
        else
        {
            Node *temp = new Node(arr[i]);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    // print value
    Node *trav = head;
    while(trav)
    {
        cout<<trav->data<<" "; // 4 3 2 1 
        trav=trav->next;
    }
}