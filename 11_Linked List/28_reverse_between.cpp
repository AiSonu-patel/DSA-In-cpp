#include<iostream>
#include <vector>
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

Node* reverseBetween(Node* head, int a, int b)
{
    vector<int>ans;
    Node *temp = head;
    while(temp)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    int i = a-1;
    int j = b-1;
    while(i<j)
    {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    Node *newHead = new Node(0);
    Node *tail = newHead;
    int index = 0;
    while(index<ans.size())
    {
        tail->next = new Node(ans[index]);
        tail = tail->next;
        index++;
    }
    Node *del = newHead;
    newHead = newHead->next;
    delete del;
    return newHead;
    
};

int main()
{
    Node *head = NULL;
    int arr[] = {1,7,5,3,9,8,10,2,2,5};
    head = CreateLL(arr, 0, 10);
    int a = 1, b = 8;

    head = reverseBetween(head, a, b);

    // print value
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" "; // 2 10 8 9 3 5 7 1 2 5
        temp = temp->next;
    }

}