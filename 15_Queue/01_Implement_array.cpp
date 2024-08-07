#include<iostream>
using namespace std;

// Implement queue using array

class Queue
{
    int *arr;
    int front, rear, size;
    public:
    // constructor
    Queue(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front==-1;
    }

    bool isFull()
    {
        return rear == size-1;
    }

    void push(int x)
    {
        if(isEmpty())
        {
            cout<<"Pushed "<<x<<" into the Queue\n";
            front = rear = 0;
            arr[0] = x;
            return;
        }
        else if(isFull())
        {
            cout<<"Queue Overflow\n";
            return;
        }
        else
        {
            rear = rear+1;
            arr[rear] = x;
            cout<<"Pushed "<<x<<" into the Queue\n";
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue Underflow\n";
            return;
        }
        else
        {
            if(front==rear)
            {
                cout<<"Popped "<<arr[front]<<" into the Queue\n";
                front = rear = -1;
            }
            else
            {
                cout<<"Popped "<<arr[front]<<" into the Queue\n";
                front = front+1;
            }
        }
    }

    int start()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    Queue q(5);
    q.push(5);
    q.push(15);
    q.push(51);
    q.pop();
    q.pop();
    // q.pop();
    int x = q.start();
    if(!q.isEmpty())
    cout<<x<<endl;
}