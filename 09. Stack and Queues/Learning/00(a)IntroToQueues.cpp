#include <bits/stdc++.h>
// Queue: FIFO data structure
// push -> using rear
// pop -> using front

// creation -> queue<int> q;
// push -> q.push(x)
// pop -> q.pop()
// size -> q.size()
// isEmpty -> q.empty()
// front element -> q.front()

// Two ways to implement queues: 1. using arrays
//                               2. using linked lists
using namespace std;
class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void push(int d)
    {
        if (rear == size)
        {
            cout << "queue is full" << endl;
        }
        else
        {
            arr[rear] = d;
            rear++;
        }
    }
    int pop()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = rear = 0;
            }
            return ans;
        }
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int front()
    {
        if (front == rear)
        {
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
    /*
    queue<int> q;
    q.push(1);
    q.push(4);
    q.push(5);
    cout<<"size of queue is: "<<q.size()<<endl;
    q.pop();
    cout<<"size of queue is: "<<q.size()<<endl;
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }
    cout<<"front element in queue is: "<<q.front()<<endl;
    */

    return 0;
}