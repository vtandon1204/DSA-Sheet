#include <bits/stdc++.h>
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // code here
    vector<pair<int, int>> ans;
    Node *tail = head;
    int len = 1;
    while (tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }
    Node *start = head;
    Node *end = tail;
    while (start->data < end->data)
    {
        int sum = start->data + end->data;
        if (sum == target)
        {
            ans.emplace_back(start->data, end->data);
            start = start->next;
            end = end->prev;
        }
        else if (sum < target)
        {
            start = start->next;
        }
        else
        {
            end = end->prev;
        }
    }
    return ans;
}