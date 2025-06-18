#include <bits/stdc++.h>
void reversePreorder(TreeNode *node, int level, vector<int> &ans)
{
    if (!node)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(node->val);
    }
    reversePreorder(node->right, level + 1, ans);
    reversePreorder(node->left, level + 1, ans);
}
void Preorder(TreeNode *node, int level, vector<int> &ans)
{
    if (!node)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(node->val);
    }
    Preorder(node->left, level + 1, ans);
    Preorder(node->right, level + 1, ans);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> rightView;
    reversePreorder(root, 0, rightView);
    return rightView;
}
vector<int> leftSideView(TreeNode *root)
{
    vector<int> leftView;
    Preorder(root, 0, leftView);
    return leftView;
}