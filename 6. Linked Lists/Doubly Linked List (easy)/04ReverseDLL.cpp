#include <bits/stdc++.h>
Node *reverseDLL(Node *head)
{
    // Your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *back = NULL;
    // Node* next = NULL;
    while (curr != NULL)
    {
        // next = curr->next;
        back = curr->prev;
        curr->prev = curr->next;
        curr->next = back;
        curr = curr->prev;
    }
    return back->prev;
}