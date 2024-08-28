#include <bits/stdc++.h>
vector<vector<int>> levelOrder(TreeNode *root)
{
    // if (!root) {
    //     return {};
    // }
    // queue<TreeNode*> q;
    // q.push(root);
    // q.push(NULL);
    // vector<vector<int>> ans;
    // vector<int> temp_vec = {};
    // while (!q.empty()) {
    //     TreeNode* temp = q.front();
    //     q.pop();

    //     if (temp == NULL) {
    //         // cout << endl;
    //         if (!temp_vec.empty()) {
    //             ans.push_back(temp_vec);
    //             temp_vec.clear();
    //         }
    //         if (!q.empty()) {
    //             q.push(NULL);
    //         }
    //     } else {
    //         // cout << temp->data << " ";
    //         temp_vec.push_back(temp->val);
    //         if (temp->left) {
    //             q.push(temp->left);
    //         }
    //         if (temp->right) {
    //             q.push(temp->right);
    //         }
    //     }
    // }
    // return ans;
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        vector<int> v;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *node = q.front();
            v.push_back(node->val);
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        ans.push_back(v);
    }
    return ans;
}