#include <bits/stdc++.h>
TreeNode *prev = NULL;
void flatten(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    if (root->right)
        flatten(root->right);
    if (root->left)
        flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}