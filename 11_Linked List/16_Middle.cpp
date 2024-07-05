#include<iostream>
#include <vector>
using namespace std;

// return a middle Linked List address
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

ListNode* middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
};

int main()
{
    ListNode *head = NULL;
    int arr[] = {1,2,3,4,5};
    head = CreatLinkedList(arr, 0, 5);

    cout<<middleNode(head); // 0x1077f38

}