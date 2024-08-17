#include <bits/stdc++.h>
void addNode(Node *head, int pos, int data)
{
    // Your code here
    Node *temp = new Node(data);
    Node *curr = head;
    int cnt = 0;
    while (curr->next != NULL)
    {
        if (cnt == pos)
        {
            temp->prev = curr;
            temp->next = curr->next;
            curr->next->prev = temp;
            curr->next = temp;
        }
        curr = curr->next;
        cnt++;
    }
    if ((curr->next == NULL) && (cnt == pos))
    {
        curr->next = temp;
        temp->prev = curr;
    }
}
