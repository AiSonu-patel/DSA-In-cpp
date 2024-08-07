#include<iostream>
using namespace std;

// Implement queue using linked list

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

class Queue
{
    Node *front;
    Node *rear;
    public:
    Queue()
    {
        front = rear = NULL;
    }

    // IsEmpty or not
    bool isEmpty()
    {
        return front==NULL;
    }

    // pushed into the queue
    void push(int x)
    {
        if(isEmpty())
        {
            cout<<"Pushed "<<x<<" into the queue\n";
            front = rear = new Node(x);
            return;
        }
        else
        {
            rear->next = new Node(x);
            if(rear->next==NULL)
            {
                cout<<"Queue Overflow\n";
                return;
            }
            cout<<"Pushed "<<x<<" into the queue\n";
            rear = rear->next;
        }
    }

    // pop
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is Underflow\n";
            return;
        }
        else
        {
            cout<<"Popped "<<front->data<<" from the Queue\n";
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int start()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            return -1;
        }
        else
        return front->data;
    }

};

int main()
{
    Queue q;
    q.push(5);
    q.push(15);
    q.push(51);
    q.push(115);
    q.pop();
    cout<<q.start()<<endl;
}