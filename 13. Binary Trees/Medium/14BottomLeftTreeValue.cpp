#include <bits/stdc++.h>
int findBottomLeftValue(TreeNode *root)
{
    if (!root)
    {
        return -1;
    }

    std::queue<TreeNode *> q;
    q.push(root);
    TreeNode *ans = nullptr;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            if (i == 0)
            {
                ans = node;
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
    }
    return ans->val;
}