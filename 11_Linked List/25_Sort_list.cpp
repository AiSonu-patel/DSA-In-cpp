#include<iostream>
#include <vector>
using namespace std;
// sort a List which contain 0 1 2

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

Node* segregate(Node *head)
{  
    Node *curr = head;
    int count0 = 0, count1 = 0, count2 = 0;
    while(curr)
    {
        if(curr->data == 0)
        count0++;
        else if(curr->data == 1)
        count1++;
        else
        count2++;

        curr = curr->next;
    }
    curr = head;
    while(count0--)
    {
        curr->data = 0;
        curr = curr->next;
    }
    while(count1--)
    {
        curr->data = 1;
        curr = curr->next;
    }
    while(count2--)
    {
        curr->data = 2;
        curr = curr->next;
    }

    return head;

};

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,2,1,2,0,2,2};
    head = CreateLL(arr, 0, 8);
    // sort a linked list
    head = segregate(head);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 0 1 1 2 2 2 2 2 
        temp = temp->next;
    }
}