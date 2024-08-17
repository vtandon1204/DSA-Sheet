#include <bits/stdc++.h>
// You are given the head of a linked list, and an integer k.
// Return the head of the linked list after swapping the values of the kth node from the 
// beginning and the kth node from the end (the list is 1-indexed).

// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]

int length(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
ListNode *swapNodes(ListNode *head, int k)
{
    int len = length(head);
    int pos = len - k + 1;
    ListNode *beg = head;
    ListNode *end = head;
    int cnt = 1;
    while (cnt < k)
    {
        beg = beg->next;
        cnt++;
    }
    cnt = 1;
    while (cnt < pos)
    {
        end = end->next;
        cnt++;
    }
    int temp = beg->val;
    beg->val = end->val;
    end->val = temp;
    return head;
}