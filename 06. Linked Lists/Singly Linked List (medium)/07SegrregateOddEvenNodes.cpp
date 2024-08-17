#include <bits/stdc++.h>
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *odd = head;
    ListNode *firsteve = head->next;
    ListNode *even = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = even->next;
        even->next = odd->next;
        even = odd->next;
    }
    odd->next = firsteve;
    return head;
}