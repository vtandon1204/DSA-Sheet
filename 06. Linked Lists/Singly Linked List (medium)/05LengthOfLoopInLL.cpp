#include <bits/stdc++.h>
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int cnt = 1;
            slow = slow->next;
            while (slow != fast)
            {
                cnt++;
                slow = slow->next;
            }
            return cnt;
        }
    }
    return 0;
}