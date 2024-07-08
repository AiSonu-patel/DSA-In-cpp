#include<iostream>
#include <vector>
using namespace std;
// check the palindrome

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
    return NULL;

    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
};

bool palindrome(Node *head)
{
    vector<int>ans;
    Node *temp = head;
    while(temp)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    int i=0, j=ans.size()-1;
    while(i<j)
    {
        if(ans[i]!=ans[j])
        {
            return 0;
        }
        i++,j--;
    }
    return 1;
}

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,2,1};
    head = CreateLinkedList(arr, 0, 5);
    // check palindrome
    cout<<palindrome(head); // true
}