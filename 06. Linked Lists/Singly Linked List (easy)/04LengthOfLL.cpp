#include <bits/stdc++.h>
int getCount(struct Node *head)
{
    // Code here
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}