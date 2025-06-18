#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto i = q.front();
        q.pop();
        TreeNode *node = i.first;
        int line = i.second.first;
        int level = i.second.second;
        mp[line][level].insert(node->val);
        if (node->left)
        {
            q.push({node->left, {line - 1, level + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {line + 1, level + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto i : mp)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                temp.push_back(k);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}