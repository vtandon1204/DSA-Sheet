#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void makeParents(TreeNode *node, unordered_map<TreeNode *, TreeNode *> &mp)
{
    queue<TreeNode *> q;
    q.push(node);
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
}
TreeNode *findStart(TreeNode *root, int start)
{
    if (!root)
        return nullptr;
    if (root->val == start)
        return root;
    TreeNode *left = findStart(root->left, start);
    if (left)
        return left;
    return findStart(root->right, start);
}
int amountOfTime(TreeNode *root, int start)
{
    unordered_map<TreeNode *, TreeNode *> mp;
    TreeNode *startNode = findStart(root, start);
    makeParents(root, mp);
    queue<TreeNode *> q;
    unordered_map<TreeNode *, bool> visited;
    q.push(startNode);
    visited[startNode] = true;
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool spread = false;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
                spread = true;
            }
            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
                spread = true;
            }
            if (mp[node] && !visited[mp[node]])
            {
                q.push(mp[node]);
                visited[mp[node]] = true;
                spread = true;
            }
        }
        if (spread)
            time++;
    }
    return time;
}