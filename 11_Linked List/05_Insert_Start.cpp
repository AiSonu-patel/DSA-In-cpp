#include<iostream>
using namespace std;

// Creating Linked List using recursion adding node at beginning
// T.C -> O(n)
// S.C -> O(n)

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

Node* CreateLinkedList(int arr[], int index, int size, Node* prev)
{
    // Base Case
    if(index==size)
    {
        return prev;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = prev;
    return CreateLinkedList(arr, index+1, size, temp);
};

int main()
{
    Node *head;
    head = NULL;

    int arr[] = {1,2,3,4,5};

    head = CreateLinkedList(arr, 0, 5, head);

    // Print value
    Node *temp;
    temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 5 4 3 2 1
        temp = temp->next;
    }
}