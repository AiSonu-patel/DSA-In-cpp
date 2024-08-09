#include<iostream>
using namespace std;

// implement Dequeue using array

class Dequeue
{
    int size, front, rear;
    int *arr;
    public:
    Dequeue(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    // IsEmpty
    bool IsEmpty()
    {
        return front==-1;
    }
    // IsFull
    bool IsFull()
    {
        return (rear+1)%size==front;
    }
    // push_front
    void push_front(int x)
    {
        // empty
        if(IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            cout<<"Pushed "<<x<<" in front\n";
            return;
        }
        else if(IsFull())
        {
            cout<<"Dequeue Overflow\n";
            return;
        }
        else
        {
            front = (front-1+size)%size;
            arr[front] = x;
            cout<<"Pushed "<<x<<" in front\n";
            return;
        }
    }
    // push-back
    void push_back(int x)
    {
        if(IsEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            cout<<"Pushed "<<x<<" in back\n";
            return;
        }
        else if(IsFull())
        {
            cout<<"Dequeue Overflow\n";
            return;
        }
        else
        {
            rear = (rear+1)%size;
            arr[rear] = x;
            cout<<"Pushed "<<x<<" in back\n";
            return;
        }
    }
    // pop_front
    void pop_front()
    {
        if(IsEmpty())
        {
            cout<<"Dequeue Underflow\n";
            return;
        }
        else
        {
            cout<<"Popped "<<arr[front]<<" from front\n";
            if(front==rear)
            front = rear = -1;
            else
            front = (front+1)%size;
        }
    }
    // pop-back
    void pop_back()
    {
        if(IsEmpty())
        {
            cout<<"Dequeue Underflow\n";
            return;
        }
        else
        {
            cout<<"Popped "<<arr[rear]<<" from back\n";
            if(front==rear)
            front = rear = -1;
            else
            rear = (rear-1+size)%size;
        }
    }
    // start
    int start()
    {
        if(IsEmpty())
        return -1;
        else
        return arr[front];
    }
    // end
    int end()
    {
        if(IsEmpty())
        return -1;
        else
        return arr[rear];
    }
};

int main()
{
    Dequeue d(5);
    d.push_back(10); // 10
    d.push_back(91); // 10 91
    d.push_back(9); // 10 91 9
    d.push_front(18); // 18 10 91 9
    d.pop_back(); // 18 10 91
    d.pop_front(); // 10 91
    cout<<d.start()<<endl; // 10
    cout<<d.end()<<endl; // 91
}