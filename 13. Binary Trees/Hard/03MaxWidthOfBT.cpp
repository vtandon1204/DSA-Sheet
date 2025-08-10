#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};
int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, long long>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        long size = q.size();
        long long mini = q.front().second;
        long long first, last;
        for (int i = 0; i < size; i++)
        {
            long currInd = q.front().second - mini;
            TreeNode *node = q.front().first;
            q.pop();
            if (i == 0)
                first = currInd;
            if (i == size - 1)
                last = currInd;
            if (node->left)
                q.push({node->left, currInd * 2 + 1});
            if (node->right)
                q.push({node->right, currInd * 2 + 2});
        }
        ans = max(ans, int(last - first + 1));
    }
    return ans;
}