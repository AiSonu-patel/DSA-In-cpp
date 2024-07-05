#include<iostream>
using namespace std;

// Delete a Node at last
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
    // balse case
    if(index==size)
    {
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
}

int main()
{
    int arr[] = {5,4,3,2,1};

    Node *head;
    head = NULL;
    head = CreateLinkedList(arr, 0, 5);

    // Delete a Node at end
    if(head!=NULL)
    {
        // Only one Node is pergent
        if(head->next==NULL)
        {
            Node *temp = head;
            delete temp;
            head = NULL;
        }
        // More then  one Node is pergent
        else
        {
            Node *curr = head;
            Node *pre = NULL;
            while(curr->next!=NULL)
            {
                pre = curr;
                curr = curr->next;
            }
            pre->next = curr->next;
            delete curr;
        }
    }


    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 5 4 3 2
        temp = temp->next;
    }

}