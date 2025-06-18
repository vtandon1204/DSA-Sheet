#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *maxFromLeftSubtree(TreeNode *node)
{
    while (node->right)
    {
        node = node->right;
    }
    return node;
}

TreeNode *minFromRightSubtree(TreeNode *node)
{
    while (node->left)
    {
        node = node->left;
    }
    return node;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    // base case
    if (!root)
        return NULL;

    if (root->val == key)
    {
        // 0 child
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // 1 child - left
        if (!root->right && root->left)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        // 1 child - right
        if (!root->left && root->right)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        if (root->left && root->right)
        {
            int maxVal = maxFromLeftSubtree(root->left)->val;
            root->val = maxVal;
            root->left = deleteNode(root->left, maxVal);
            // // OR
            // int minVal = minFromRightSubtree(root->right)->val;
            // root->val = minVal;
            // root->right = deleteNode(root->right, minVal);
            return root;
        }
    }
    else if (root->val > key)
    {
        // find left
        root->left = deleteNode(root->left, key);
        return root;
    }
    else
    {
        // find right
        root->right = deleteNode(root->right, key);
        return root;
    }
    return root;
}