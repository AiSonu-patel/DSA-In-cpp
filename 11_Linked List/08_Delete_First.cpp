#include<iostream>
using namespace std;
//

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

Node* CreateLinkedList(int arr[], int index, int size)
{
    if(index == size)
    {
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
}

int main()
{
    Node *head;
    head = NULL;

    int arr[] = {1,2,3,4,5};

    head = CreateLinkedList(arr, 0, 5);
    // Delete Node at start
    if(head!=NULL)
    {
        Node *temp2;
        temp2 = head;
        head = head->next;
        delete temp2;
    }

    // print the value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next; // 2 3 4 5
    }
}