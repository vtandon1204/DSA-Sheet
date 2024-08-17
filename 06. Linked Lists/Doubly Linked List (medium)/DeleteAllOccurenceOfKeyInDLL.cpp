#include <bits/stdc++.h>
Node *deleteAllOccurrences(Node *head, int k)
{
    // Write your code here
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = head->next;
            }
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;
            if (nextNode)
            {
                nextNode->prev = prevNode;
            }
            if (prevNode)
            {
                prevNode->next = nextNode;
            }
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}