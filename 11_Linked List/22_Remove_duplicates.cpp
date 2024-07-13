#include<iostream>
#include <vector>
using namespace std;
// remove a duplicates value from LinkedList

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

Node* removeDuplicate(Node *head)
{
    vector<int>ans;
    Node *curr = head->next;
    ans.push_back(head->data);
    while(curr)
    {
        if(ans[ans.size()-1] != curr->data)
        {
            ans.push_back(curr->data);
        }
        curr = curr->next;
    }
    curr = head;
    int index = 0;
    while(index<ans.size())
    {
        curr->data = ans[index];
        index++;
        curr = curr->next;
    }
    curr = head;
    int size = ans.size()-1;
    while(size--)
    {
        curr=curr->next;
    }
    curr->next = NULL;
    return head;

};

int main()
{
    Node *head = NULL;
    int arr[] = {2,2,2,3,3,4,4};
    // create a linked list
    head = CreateLL(arr, 0, 7);
    // remove duplicates value
    head = removeDuplicate(head);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 2 3 4
        temp = temp->next;
    }
}