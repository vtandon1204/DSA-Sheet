#include <bits/stdc++.h>
// Given the head of a linked list and an integer val, remove all the nodes of the linked list 
// that has Node.val == val, and return the new head.

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
ListNode *removeElements(ListNode *head, int val)
{
    if (head == NULL)
    {
        return head;
    }
    ListNode *temp = head;
    while (temp)
    {
        if (temp->val == val)
        {
            if (temp == head)
            {
                head = head->next;
            }
            else
            {
                ListNode *prev = head;
                while (prev->next != temp)
                {
                    prev = prev->next;
                }
                ListNode *next = temp->next;
                prev->next = next;
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