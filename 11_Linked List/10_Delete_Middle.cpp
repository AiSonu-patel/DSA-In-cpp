#include<iostream>
using namespace std;

// Delete a Node at particular index
class Node
{
    public:
    int data;
    Node *next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

Node* CreateLinkedList(int arr[], int index, int size)
{
    // base case
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
}

int main()
{
    Node *head;
    head=NULL;
    int arr[] = {1,2,3,4,5};
    head = CreateLinkedList(arr, 0, 5);

    // Delete a Node at particular index;
    int x = 1;
    if(x==1)
    {
        Node *temp2 = head;
        head = head->next;
        delete temp2;
    }
    else
    {
        x--;
        Node *curr = head;
        Node *pre = NULL;
        while(x--)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        delete curr;
    }

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 2 3 4 5
        temp = temp->next;
    }
}