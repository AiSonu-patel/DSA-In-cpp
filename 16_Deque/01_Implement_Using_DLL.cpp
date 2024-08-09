#include<iostream>
using namespace std;

// Implement Dequeue using Doubly Linked List

class Node
{
    public:
    int data;
    Node *next, *prev;

    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }
};

class Dequeue
{
    Node *front, *rear;
    public:
    Dequeue()
    {
        front = rear = NULL;
    }

    // push front
    void push_front(int x)
    {
        // empty
        if(front==NULL)
        {
            front = rear = new Node(x);
            cout<<"Pushed "<<x<<" in front of Dequeue\n";
            return;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout<<"Pushed "<<x<<" in front of Dequeue\n";
            return;
        }
    }
    // push back
    void push_back(int x)
    {
        // empty
        if(front==NULL)
        {
            front = rear = new Node(x);
            cout<<"Pushed "<<x<<" in back of Dequeue\n";
            return;
        }
        else
        {
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout<<"Pushed "<<x<<" in back of Dequeue\n";
            return;
        }
    }
    // pop front
    void pop_front()
    {
        // empty
        if(front==NULL)
        {
            cout<<"Dequeue Underflow\n";
            return;
        }
        else
        {
            Node *temp = front;
            cout<<"Popped "<<temp->data<<" from front\n";
            front = front->next;
            delete temp;
            if(front)
            front->prev = NULL;
            else
            rear = NULL;
        }
    }
    // pop back
    void pop_back()
    {
        // empty
        if(front==NULL)
        {
            cout<<"Dequeue Underflow\n";
            return;
        }
        else
        {
            Node *temp = rear;
            cout<<"Popped "<<temp->data<<" from back\n";
            rear = rear->prev;
            delete temp;
            if(rear)
            rear->next = NULL;
            else
            front = NULL;
        }
    }
    // start
    int start()
    {
        if(front==NULL)
        return -1;
        else
        return front->data;
    }
    // end
    int end()
    {
        if(front==NULL)
        return -1;
        else 
        return rear->data;
    }
};

int main()
{
    Dequeue d;
    d.push_back(5); // 5
    d.push_front(8); // 8 5
    d.pop_back(); // 8
    cout<<d.start()<<endl; // 8
    cout<<d.end()<<endl; // 8
}