#include<iostream>
#include <vector>
using namespace std;

// Reverse a Linked List
class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

ListNode* CreatLinkedList(int arr[], int index, int size)
{
    if(index==size)
    {
        return NULL;
    }
    ListNode *temp;
    temp = new ListNode(arr[index]);
    temp->next = CreatLinkedList(arr, index+1, size);
    return temp;
};

ListNode* reverseList(ListNode *head)
{
    vector<int>ans;
    ListNode *temp = head;
    while(temp)
    {
        ans.push_back(temp->val);
        temp = temp->next;
    }
    int i = ans.size()-1;
    temp = head;
    while(temp)
    {
        temp->val = ans[i];
        i--;
        temp = temp->next;
    }
    return head;
    
};

int main()
{
    ListNode *head = NULL;
    int arr[] = {1,2,3,4,5};
    head = CreatLinkedList(arr, 0, 5);
    head = reverseList(head);

    // print value
    ListNode *temp = head;
    while(temp)
    {
        cout<<temp->val<<" "; // 5 4 3 2 1
        temp = temp->next;
    }

}