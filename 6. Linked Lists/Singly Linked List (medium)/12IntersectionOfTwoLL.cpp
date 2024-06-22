#include <bits/stdc++.h>
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int len1 = 0;
    int len2 = 0;
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        len1++;
    }
    while (temp2 != NULL)
    {
        temp2 = temp2->next;
        len2++;
    }
    temp1 = headA;
    temp2 = headB;
    int count = 0;
    if (len1 >= len2)
    {
        count = len1 - len2;
        while (count > 0)
        {
            count--;
            temp1 = temp1->next;
        }
    }
    else
    {
        count = len2 - len1;
        while (count > 0)
        {
            count--;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}
