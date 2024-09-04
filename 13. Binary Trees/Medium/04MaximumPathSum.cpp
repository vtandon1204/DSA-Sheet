#include <bits/stdc++.h>
int maxSum = INT_MIN;
int func(TreeNode *root)
{
    if (!root)
        return 0;
    int leftSum = max(0, func(root->left));
    int rightSum = max(0, func(root->right));

    maxSum = max(maxSum, leftSum + rightSum + root->val);
    int ans = root->val + max(leftSum, rightSum);
    return ans;
}
int maxPathSum(TreeNode *root)
{
    func(root);
    return maxSum;
}