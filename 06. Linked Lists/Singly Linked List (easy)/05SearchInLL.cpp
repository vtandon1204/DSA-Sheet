#include <bits/stdc++.h>
bool searchKey(int n, struct Node *head, int key)
{
    // Code here
    // if(head->data == key){
    //     return true;
    // }
    Node *temp = head;
    while (temp)
    {
        if (temp->data == key)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}