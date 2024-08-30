#include <bits/stdc++.h>
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (true)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}