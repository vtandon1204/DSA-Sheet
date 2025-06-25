#include <bits/stdc++.h>
void MyStack ::push(int x)
{
    top++;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    int x = -1;
    if (top >= 0)
    {
        x = arr[top];
        top--;
    }
    return x;
}