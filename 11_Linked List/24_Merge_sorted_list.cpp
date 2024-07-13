#include<iostream>
#include <vector>
using namespace std;
// Merge two sorted List

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

Node* CreateLL1(int arr[], int index, int size)
{
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLL1(arr, index+1, size);
    return temp;
};

Node* CreateLL2(int arr[], int index, int size)
{
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLL2(arr, index+1, size);
    return temp;
};

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node *head = new Node(0);
    Node *tail = head;
    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if(head1)
    tail->next = head1;
    else
    tail->next = head2;

    tail = head;
    head = head->next;
    delete tail;
    return head;

};

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head = NULL;
    int arr1[] = {2,4,5,7};
    int arr2[] = {3,4,4,6,8,10};
    // create a linked list
    head1 = CreateLL1(arr1, 0, 4);
    head2 = CreateLL2(arr2, 0, 6);
    // merge two sorted list
    head = sortedMerge(head1, head2);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 2 3 4 4 4 5 6 7 8 10
        temp = temp->next;
    }
}