#include <bits/stdc++.h>
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root)
    {
        if (root->val == val)
        {
            return root;
        }
        if (root->val > val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
    // if (!root) {
    //     return NULL;
    // }
    // if (root->val == val) {
    //     return root;
    // }
    // if (root->val > val) {
    //     return searchBST(root->left, val);
    // } else {
    //     return searchBST(root->right, val);
    // }
}