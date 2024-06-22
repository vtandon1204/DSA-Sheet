#include <bits/stdc++.h>
ListNode *middleNode(ListNode *head)
{
    ListNode *tail = head;
    int first = 0;
    int last = 1;
    while (tail->next != NULL)
    {
        tail = tail->next;
        last++;
    }

    ListNode *midNode = head;
    int mid = (first + last) / 2;
    int cnt = 0;

    while (cnt < mid)
    {
        midNode = midNode->next;
        cnt++;
    }

    return midNode;
}