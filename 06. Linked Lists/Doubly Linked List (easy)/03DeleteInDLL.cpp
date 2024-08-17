#include <bits/stdc++.h>
Node *deleteNode(Node *head, int x)
{
    // Your code here
    if (x == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        // delete temp;
        // return head;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < x)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        // curr->next->prev=prev;
        curr->next = NULL;
        // delete curr;
    }
    return head;
}
