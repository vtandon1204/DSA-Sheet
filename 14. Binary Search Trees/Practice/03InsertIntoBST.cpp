#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    // base case
    if (!root)
    {
        TreeNode *node = new TreeNode(val);
        return node;
    }
    // left insertion
    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    // right insertion
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}