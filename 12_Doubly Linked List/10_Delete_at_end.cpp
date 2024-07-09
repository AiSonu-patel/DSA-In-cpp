#include<iostream>
using namespace std;

// delete at last node
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
    // Delete at end
    if(head != NULL)
    {
        if(head->next==NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node * curr = head;
            while(curr->next)
            {
                curr = curr->next;
            }
            curr->prev->next = NULL;
            delete curr;
        }
    }

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 1 2 3 4
        temp = temp->next;
    }
}