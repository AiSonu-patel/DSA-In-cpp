#include<iostream>
using namespace std;

// delete at given any position
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

Node* CreateDLL(int arr[], int index, int size, Node *back)
{
    if(index==size)
    return NULL;
    Node *temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = CreateDLL(arr, index+1, size, temp);
    return temp;
};

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,4,5};
    head = CreateDLL(arr, 0, 5, NULL);
    // Delete at given any position
    int pos = 3;
    if(pos==1)
    {
        if(head->next==NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
        }
    }
    else
    {
        Node *curr = head;
        while(--pos)
        {
            curr=curr->next;
        }
        // delete at end
        if(curr->next==NULL)
        {
            curr->prev->next = NULL;
            delete curr;
        }
        // delete at middle
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 1 2 4 5
        temp = temp->next;
    }
}