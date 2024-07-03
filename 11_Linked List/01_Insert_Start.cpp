#include<iostream>
using namespace std;

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
    // it is create by static way
    // Node A1(4); 

    // Create Dynamic way

    // Node *head;
    // head = new Node(4);
    // cout<<head->data<<endl;
    // cout<<head->next<<endl;

    // Insert the Node at beginning


    Node *head;
    head = NULL;

    int arr[]= {1,2,3,4,5};

    for(int i=0; i<5; i++)
    {
        // Linked list doesnt exist
        if(head==NULL)
        {
            head = new Node(arr[i]);
        }
        // Linked list exist karti
        else
        {
            Node *temp;
            temp = new Node(arr[i]);
            temp->next = head;
            head = temp;
        }
    }
        // Print the value:
        Node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" "; // 5 4 3 2 1
            temp=temp->next;
        };
}