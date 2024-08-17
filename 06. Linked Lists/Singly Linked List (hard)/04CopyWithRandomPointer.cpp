#include <bits/stdc++.h>
Node *copyRandomList(Node *head)
{
    if (!head)
    {
        return NULL;
    }
    unordered_map<Node *, Node *> ans;
    Node *temp = head;
    while (temp)
    {
        ans[temp] = new Node(temp->val);
        temp = temp->next;
    }
    for (auto it : ans)
    {
        cout << it.first->val << " " << it.second->val << endl;
    }
    temp = head;
    while (temp)
    {
        ans[temp]->next = ans[temp->next];
        ans[temp]->random = ans[temp->random];
        temp = temp->next;
    }
    return ans[head];
}