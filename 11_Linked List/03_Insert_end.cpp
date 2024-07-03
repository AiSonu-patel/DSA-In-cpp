#include<iostream>
using namespace std;

// Insert the value at end
class Node
{
    public:
    int data;
    Node *next;
    Node (int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *head, *tail;
    tail = head = NULL;

    int arr[] = {1,2,3,4,5};
    for(int i=0; i<5; i++)
    {
        // Lnked list is empty
        if(head==NULL)
        {
            head = new Node(arr[i]);
            tail = head;
        }
        // Linked list exist karti hai
        else
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }
    // Print the values:
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 1 2 3 4 5
        temp=temp->next;
    }
}
