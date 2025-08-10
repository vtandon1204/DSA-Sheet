#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode *predecessor(TreeNode *node)
{
    TreeNode *pred = node->left;
    while (pred->right && pred->right != node)
    {
        pred = pred->right;
    }
    return pred;
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *pred;
    TreeNode *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            ans.push_back(curr->val);
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
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}