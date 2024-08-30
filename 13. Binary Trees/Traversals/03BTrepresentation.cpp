#include <bits/stdc++.h>
void create_tree(node *root0, vector<int> &vec)
{
    if (vec.empty())
        return;

    queue<node *> q;
    q.push(root0);

    int i = 1; // Start from the second element in vec
    while (!q.empty() && i < vec.size())
    {
        node *current = q.front();
        q.pop();

        // Assign left child
        if (i < vec.size())
        {
            current->left = newNode(vec[i++]);
            q.push(current->left);
        }

        // Assign right child
        if (i < vec.size())
        {
            current->right = newNode(vec[i++]);
            q.push(current->right);
        }
    }
}