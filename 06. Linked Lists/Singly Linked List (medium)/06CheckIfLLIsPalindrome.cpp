#include <bits/stdc++.h>
ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *newHead = reverse(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(ListNode *head)
{
    // stack<int> st;
    // ListNode* temp = head;
    // while(temp!=NULL){
    //     st.push(temp->val);
    //     temp=temp->next;
    // }
    // temp = head;
    // while(temp!=NULL){
    //     if(st.top()!=temp->val){
    //         return false;
    //     }
    //     else{
    //         st.pop();
    //         temp=temp->next;
    //     }
    // }
    // return true;

    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next->next != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *rev = reverse(slow->next);
    ListNode *first = head;
    ListNode *second = rev;
    while (second != NULL)
    {
        if (first->val != second->val)
        {
            reverse(rev);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(rev);
    return true;
}