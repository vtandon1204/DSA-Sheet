#include <bits/stdc++.h>
// Stacks : LIFO data structure
// creation -> stack<int> st;
// insert -> push operation (st.push(x))
// remove -> pop operation (st.pop())
// peak -> top operation (st.top())
// empty -> st.empty()

using namespace std;
// Two ways to implement stacks: 1. using arrays
//                               2. using linked lists
class Stack
{
    // properties/variables
public:
    int top;
    int *arr;
    int size;
    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    // function/methods
    void push(int d)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = d;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    /*
    // creation of stack
    stack<int> st;
    // push operation
    st.push(3);
    st.push(7);
    // pop operation
    st.pop();
    // top operation
    cout << "printing top element: " << st.top() << endl;
    // empty operation
    if (st.empty()) cout << "stack is empty" << endl;
    else cout << "stack is not empty" << endl;
    // size operation
    cout << "stack size is: " << st.size() << endl;
    */

    Stack st(5);

    st.push(3);
    st.push(2);
    st.pop();
    st.push(4);
    st.push(6);
    st.pop();
    st.pop();
    st.pop();
    // st.pop();
    cout << st.peek() << endl;
    return 0;
}