#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *first;
TreeNode *mid;
TreeNode *second;
TreeNode *prevv;
void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);

    if (prevv && root->val < prevv->val)
    {
        // first violation
        if (!first)
        {
            first = prevv;
            mid = root;
        }
        // second violation
        else
        {
            second = root;
        }
    }
    prevv = root;
    inorder(root->right);
}
void recoverTree(TreeNode *root)
{
    first = mid = second = NULL;
    prevv = new TreeNode(INT_MIN);
    inorder(root);

    if (first && second)
        swap(first->val, second->val);
    else if (first && mid)
        swap(first->val, mid->val);
}