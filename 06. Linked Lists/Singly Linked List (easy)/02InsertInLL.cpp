#include <bits/stdc++.h>
class Node
{
public:
    int data;
    Node *next;

    Node(int data) // constructor
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "node with data " << val << " is deleted" << endl;
    }
};
Node *insertAtBegining(Node *head, int x)
{
    // Your code here
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
    return head;
}

// Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)
{
    // Your code here
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *temp = new Node(x);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    curr = temp;
    return head;
}