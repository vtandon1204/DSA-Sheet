#include <bits/stdc++.h>
TreeNode *predecessor(TreeNode *node)
{
    TreeNode *pred = node->left;
    while (pred->right && pred->right != node)
    {
        pred = pred->right;
    }
    return pred;
}

// Helper function to print nodes in reverse order
void printReverse(TreeNode *start, TreeNode *end, vector<int> &ans)
{
    vector<int> temp;
    TreeNode *node = start;
    while (node != end)
    {
        temp.push_back(node->val);
        node = node->right;
    }
    temp.push_back(end->val);
    reverse(temp.begin(), temp.end());
    ans.insert(ans.end(), temp.begin(), temp.end());
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode dummy(0);
    dummy.left = root;
    TreeNode *curr = &dummy;
    TreeNode *pred;

    while (curr)
    {
        if (!curr->left)
        {
            curr = curr->right;
        }
        else
        {
            pred = predecessor(curr);
            if (!pred->right)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                printReverse(curr->left, pred, ans); // Postorder-like reversal before cutting the thread
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}