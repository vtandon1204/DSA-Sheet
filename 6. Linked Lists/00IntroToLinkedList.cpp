// Linked List: linear data structure formed by collection of nodes
// Node consist of data and address of the node next to it.

// We cannot change the size of an array at the run time.
// In vectors also, a new storage is created and values are copied.
// Thus, Linked List is used which dynamic in nature (grow/shrink at run time)
// -> no memory wastage
// -> easy insertion and deletion (because no shifting needed)
// -> no need of continous memory addresses
#include <bits/stdc++.h>
using namespace std;
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
};

// **** Traversal ****
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "X" << endl;
}

// **** Insertion ****
void InsertAtHead(Node *&head, int data) // reference isiliye liya kyunki hum chahte hn ki original linked list pe kaam ho
{
    Node *temp = new Node(data); // creating new node
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data); // creating new node
    tail->next = temp;
    // tail = tail->next;
    tail = temp;
}

void InsertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    Node *temp = new Node(data); // creating new node
    Node *curr = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        curr = curr->next;
        cnt++;
    }
    if (curr->next == NULL)
    {
        InsertAtTail(tail, data);
        return;
    }
    temp->next = curr->next;
    curr->next = temp;
}
int main()
{
    // creating first node
    Node *node1 = new Node(5);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    // inserting new node at head position
    InsertAtHead(head, 12);
    print(head);
    InsertAtHead(head, 14);
    print(head);

    // inserting new node at tail position
    InsertAtTail(tail, 32);
    print(head);
    InsertAtTail(tail, 121);
    print(head);

    // inserting new node at certain position
    InsertAtPosition(head, tail, 3, 100);
    print(head);
    InsertAtPosition(head, tail, 1, 144); // at head
    print(head);
    InsertAtPosition(head, tail, 8, 170); // at tail
    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
}