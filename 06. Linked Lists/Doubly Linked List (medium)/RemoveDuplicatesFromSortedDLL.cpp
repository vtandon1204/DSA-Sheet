#include <bits/stdc++.h>
Node *removeDuplicates(struct Node *head)
{
    // Your code here
    Node *temp = head;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        while (nextNode != NULL && temp->data == nextNode->data)
        {
            nextNode = nextNode->next;
        }
        temp->next = nextNode;
        if (nextNode)
            nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}