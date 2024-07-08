#include<iostream>
using namespace std;

// Remove every Nth Node (nth=3)
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
    if(index==size)
    {
        return NULL;
    }
    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
};

Node* deleteK(Node *head, int x)
{
    int count=1;
    if(x==1)
    return NULL;
    Node *pre=NULL, *curr=head;
    while(curr)
    {
        if(count==x)
        {
            pre->next = curr->next;
            delete curr;
            curr=pre->next;
            count=1;
        }
        else
        {
            pre=curr;
            curr=curr->next;
            count++;
        }        
    }
    return head;
};

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    head = CreateLinkedList(arr, 0, 10);
    // delete every kth Node
    head = deleteK(head, 3);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 1 2 4 5 7 8 10
        temp = temp->next;
    }
}