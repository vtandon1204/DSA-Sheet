#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void makeParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *parent = q.front();
        q.pop();
        if (parent->left)
        {
            q.push(parent->left);
            mp[parent->left] = parent;
        }
        if (parent->right)
        {
            q.push(parent->right);
            mp[parent->right] = parent;
        }
    }
    // for (auto& [i, j] : mp) {
    //     cout << i->val << " " << j->val << endl;
    // }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> ans;
    unordered_map<TreeNode *, TreeNode *> mp;
    makeParents(root, mp);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    int dist = 0;
    q.push(target);
    visited[target] = true;
    while (!q.empty())
    {
        int size = q.size();
        if (dist == k)
            break;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (mp[node] && !visited[mp[node]])
            {
                q.push(mp[node]);
                visited[mp[node]] = true;
            }
        }
        dist++;
    }
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}