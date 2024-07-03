#include<iostream>
using namespace std;
// Insert Node at particular position

class Node
{
    public:
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node* CreateLinkedList(int arr[], int index, int size)
{
    // base case
    if(index == size)
    {
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size); 
    return temp;
};

int main()
{
    Node *head;
    head = NULL;

    int arr[] = {1,2,3,5,6};
    int x = 3;
    int val = 4;

    head = CreateLinkedList(arr, 0, 5);

    // Insert Node at particular position
    Node *temp = head;
    x--;
    while(x--)
    {
        temp=temp->next;
    }
    Node *newNode;
    newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    // Print the value
    Node *temp1;
    temp1 = head;
    while(temp1)
    {
        cout<<temp1->data<<" "; // 1 2 3 4 5 6
        temp1=temp1->next;
    }
}