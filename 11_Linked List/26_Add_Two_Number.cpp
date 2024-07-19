#include<iostream>
using namespace std;

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
    return NULL;
    Node *temp = new Node(arr[index]);
    temp->next = CreateLL1(arr, index+1, size);
    return temp;
};

Node* CreateLL2(int arr[], int index, int size)
{
    if(index==size)
    return NULL;
    Node *temp = new Node(arr[index]);
    temp->next = CreateLL2(arr, index+1, size);
    return temp;
};

Node *reverseLL(Node *curr, Node *prev)
{
    if(curr==NULL)
    return prev;
    Node *front = curr->next;
    curr->next = prev;
    return reverseLL(front, curr);
};

Node* addTwoLists(Node *head1, Node *head2)
{
    head1 = reverseLL(head1, NULL);
    head2 = reverseLL(head2, NULL);
    Node *curr1 = head1, *curr2 = head2;
    Node *head = new Node(0);
    Node *tail = head;
    int carry = 0;
    while(curr1 && curr2)
    {
        int sum = curr1->data+curr2->data+carry;
        tail->next = new Node(sum%10);
        tail = tail->next;
        curr1 = curr1->next;
        curr2 = curr2->next;
        carry = sum/10;
    }

    while(curr1)
    {
        int sum = curr1->data+carry;
        tail->next = new Node(sum%10);
        tail = tail->next;
        curr1 = curr1->next;
        carry = sum/10;
    }

    while(curr2)
    {
        int sum = curr2->data+carry;
        tail->next = new Node(sum%10);
        tail = tail->next;
        curr2 = curr2->next;
        carry = sum/10;
    }

    while(carry)
    {
        tail->next = new Node(carry%10);
        tail = tail->next;
        carry /=10; 
    }

    head = reverseLL(head->next, NULL);
    return head;
};

int main()
{
    int arr1[] = {9,7,6,8,4};
    int arr2[] = {6,4,3,8};
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head = NULL;
    // CreateLL1
    head1 = CreateLL1(arr1, 0, 5);
    // CreateLL2
    head2 = CreateLL2(arr2, 0, 4);
    // add two linked list
    head = addTwoLists(head1, head2);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}