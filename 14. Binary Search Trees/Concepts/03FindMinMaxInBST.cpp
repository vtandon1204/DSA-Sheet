#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
pair<int, int> MinMaxInBST(TreeNode *root)
{
    int min_val = root->val;
    int max_val = root->val;
    TreeNode *temp = root;
    while (temp->left)
    {
        temp = temp->left;
        min_val = temp->val;
    }
    temp = root;
    while (root->right)
    {
        temp = temp->right;
        max_val = temp->val;
    }
    pair<int, int> ans;
    ans.first = min_val;
    ans.second = max_val;
    return ans;
}