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

Node* CreateLinkedList(int arr[], int index, int size)
{
    // base case
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
};

bool isPalindrome(Node *head)
{
    if(head->next==NULL)
    {
        return 1;
    }
    // count the number of nodes
    int count=0;
    Node *temp = head;
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    count/=2;
    Node *curr = head, *pre = NULL;
    while(count--)
    {
        pre = curr;
        curr = curr->next;
    }
    pre->next = NULL;
    // reverse node;
    pre = NULL;
    Node *fut = NULL;
    while(curr)
    {
        fut = curr->next;
        curr->next = pre;
        pre = curr;
        curr = fut;
    }
    // check the palindrome
    Node *head1 = head, *head2 = pre;
    while(head1)
    {
        if(head1->data != head2->data)
        {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;
};

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,2,1};
    head = CreateLinkedList(arr, 0, 5);

    // is palindrome
    cout<<isPalindrome(head); // 1
}