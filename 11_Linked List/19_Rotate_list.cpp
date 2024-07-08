#include<iostream>
using namespace std;

// rotate a list k time

class Node
{
    public:
    int data;
    Node *next;
    Node(int valu)
    {
        data = valu;
        next = NULL;
    }
};

Node* CreateLiskedList(int arr[], int index, int size)
{
    // base case
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLiskedList(arr, index+1, size);
    return temp;
};

Node* rotateK(Node *head, int k)
{
    if(head==NULL || head->next==NULL)
    return head;

    int count=0;
    Node *temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    k=k%count;
    if(k==0)
    return head;
    count-=k;
    Node *curr = head, *pre = NULL;
    while(count--)
    {
        pre=curr;
        curr = curr->next;
    }
    pre->next = NULL;
    Node *tail = curr;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = head;
    head = curr;
    return head;
};

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,4,5,6,7,8};
    head = CreateLiskedList(arr, 0, 8);
    // rotate Node k time
    head = rotateK(head, 2);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 7 8 1 2 3 4 5 6
        temp = temp->next;
    }
}