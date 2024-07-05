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
    int count=0;
    ListNode *temp = head;
    while(temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    count/=2;
    temp = head;
    while(count--)
    temp = temp->next;

    return temp;
};

int main()
{
    ListNode *head = NULL;
    int arr[] = {1,2,3,4,5};
    head = CreatLinkedList(arr, 0, 5);

    cout<<middleNode(head); // 0x1167f38

}