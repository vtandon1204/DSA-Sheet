// Doubly Linked List: prev pointer, data, next pointer
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "X" << endl;
}

int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void InsertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    Node *temp = new Node(data);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
}

void InsertAtPosition(Node *head, int pos, int data)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    Node *temp = new Node(data);
    Node *curr = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        curr = curr->next;
        cnt++;
    }
    if (curr->next == NULL)
    {
        InsertAtTail(head, data);
        return;
    }
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}
int main()
{
    // Node *node1 = new Node(5);
    Node *head = NULL;
    print(head);
    cout << "length of DLL is: " << getLength(head) << endl;
    // cout << "head: " << head->data << endl;

    InsertAtHead(head, 7);
    print(head);
    cout << "head: " << head->data << endl;

    InsertAtTail(head, 9);
    print(head);
    cout << "head: " << head->data << endl;

    InsertAtPosition(head, 2, 11);
    print(head);
    cout << "head: " << head->data << endl;
}