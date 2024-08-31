#include <bits/stdc++.h>
pair<int, int> MinMaxInBST(Node *root)
{
    int min_val = root->data;
    int max_val = root->data;
    Node *temp = root;
    while (root->left)
    {
        root = root->left;
        min_val = root->data;
    }
    root = node;
    while (root->right)
    {
        root = root->right;
        max_val = root->data;
    }
    pair<int, int> ans;
    ans.first = min_val;
    ans.second = max_val;
    return ans;
}