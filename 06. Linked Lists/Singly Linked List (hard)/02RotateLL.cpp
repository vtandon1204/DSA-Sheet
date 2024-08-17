#include <bits/stdc++.h>
int length(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    cout << len << endl;
    return len;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int len = length(head);
    k = k % len;
    int pos = len - k;
    ListNode *temp = head;
    int cnt = 0;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    ListNode *curr = temp;
    cnt = 0;
    while (cnt < k)
    {
        curr = curr->next;
        cnt++;
    }
    curr->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
}