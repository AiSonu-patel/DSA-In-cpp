#include<iostream>
#include <vector>
using namespace std;
// remove a duplicates value from LinkedList

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

Node* CreateLL(int arr[], int index, int size)
{
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLL(arr, index+1, size);
    return temp;
};

Node* removeDuplicate(Node *head)
{
    Node *prev = head;
    Node *curr = head->next;
    while(curr)
    {
        if(curr->data == prev->data)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
};

int main()
{
    Node *head = NULL;
    int arr[] = {2,2,2,3,3,4,4};
    // create a linked list
    head = CreateLL(arr, 0, 7);
    // remove duplicates value
    head = removeDuplicate(head);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 2 3 4
        temp = temp->next;
    }
}