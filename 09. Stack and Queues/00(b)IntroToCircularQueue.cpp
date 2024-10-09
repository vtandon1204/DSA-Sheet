#include <iostream>
// Circular Queue
using namespace std;
class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    bool push(int d)
    {
        if ((front == 0 && rear == size) || (rear == (front - 1) % (size - 1)))
        {
            cout << "queue is full" << endl;
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = d;
        return true;
    }
    int pop()
    {
        if (front == -1)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear != 0 && front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
    
};
int main()
{
    return 0;
}