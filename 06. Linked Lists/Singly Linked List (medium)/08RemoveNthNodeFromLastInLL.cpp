#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data) // constructor
    {
        this->data = data;
        this->next = NULL;
    }

    ~ListNode()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "node with data " << val << " is deleted" << endl;
    }
};
void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "X" << endl;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = 1;
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    int pos = len - n + 1;
    ListNode *curr = head;
    ListNode *prev = NULL;
    if (pos == 0)
    {
        ListNode *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            ListNode *temp1 = curr;
            prev->next = temp1->next;
            curr->next = NULL;
            delete temp1;
        }
        else
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    print(head);
    head = removeNthFromEnd(head, 1);
    print(head);
}