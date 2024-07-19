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

Node* CreateLL(int arr[], int index, int size)
{
    if(index==size)
    return NULL;
    Node *temp = new Node(arr[index]);
    temp->next = CreateLL(arr, index+1, size);
    return temp;
};

Node* reverseIt (Node *head, int k)
{
    Node *first = new Node(0);
        first->next = head;
        head = first;
        int x;
        Node *second, *prev, *curr, *front;
        
        while(first->next)
        {
            x = k;
            second = first->next;
            prev = first;
            curr = first->next;
            
            while(x && curr)
            {
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
                x--;
            }
            
            first->next = prev;
            second->next = curr;
            first = second;
        }
        
        first = head;
        head = head->next;
        delete first;
        
        return head;
};

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,2,4,5,6,7,8};
    head = CreateLL(arr, 0, 8);
    int k = 4;
    head = reverseIt(head, k);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 4 2 2 1 8 7 6 5
        temp = temp->next;
    }

}