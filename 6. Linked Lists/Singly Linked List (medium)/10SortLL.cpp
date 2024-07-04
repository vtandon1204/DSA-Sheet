int length(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
ListNode *sortList(ListNode *head)
{
    ListNode *curr = head;
    int cnt = 1;
    int len = length(head);
    while (cnt < len)
    {
        while (curr->next != NULL)
        {
            if (curr->val > curr->next->val)
            {
                swap(curr->val, curr->next->val);
                curr = curr->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        curr = head;
        cnt++;
    }
    return head;
}