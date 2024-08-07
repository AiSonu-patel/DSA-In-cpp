#include<iostream>
#include<queue>
using namespace std;

// Print all number in every window of size k;

void display(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
};

int main()
{
    int arr[] = {3,6,2,7,8,11};
    int n = 6;
    int k = 3;

    queue<int>q;
    for(int i=0; i<k-1; i++)
    q.push(arr[i]);

    for(int i=k-1; i<n; i++)
    {
        q.push(arr[i]);
        display(q);
        q.pop();
    }

    return 0;

    // ans
    // 3 6 2 
    // 6 2 7 
    // 2 7 8 
    // 7 8 1

}