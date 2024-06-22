#include <bits/stdc++.h>
int midPosition(ListNode *head)
{
    ListNode *tail = head;
    int first = 0;
    int last = 1;
    while (tail->next != NULL)
    {
        tail = tail->next;
        last++;
    }
    int mid = (first + last) / 2;
    return mid;
}
ListNode *deleteMiddle(ListNode *head)
{
    int pos = midPosition(head);
    if (head->next == NULL)
    {
        return NULL;
    }
    ListNode *curr = head;
    ListNode *prev = NULL;
    int cnt = 0;
    while (cnt < pos)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return head;
}