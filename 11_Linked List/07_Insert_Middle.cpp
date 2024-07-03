#include<iostream>
using namespace std;
// Insert Node at particular position using recurse

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

void InsertMiddle(int arr[], int move, int val, Node *temp)
{
    // base case
    if(move==0)
    {
        Node *temp2;
        temp2 = new Node(val);
        temp2->next = temp->next;
        temp->next = temp2;
        return;
    }
    temp = temp->next;
    InsertMiddle(arr, move-1, val, temp);
    
};

int main()
{
    int arr[] = {1,2,3,5,6};
    Node *head;
    head = NULL;
    head = CreateLinkedList(arr, 0, 5);

    int x = 3;
    int val = 4;
    x--;
    // Insert Node at particular position
    Node *temp;
    temp = head;
    InsertMiddle(arr, x, val, temp);
    

    // Print the value
    temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 1 2 3 4 5 6
        temp=temp->next;
    }
}