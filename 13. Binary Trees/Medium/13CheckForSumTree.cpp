#include <bits/stdc++.h>
pair<bool, int> sum(Node *root)
{
    if (!root)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (!root->left && !root->right)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = sum(root->left);
    pair<bool, int> right = sum(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool cond = root->data == left.second + right.second;

    pair<bool, int> ans;
    ans.first = (leftAns && rightAns && cond);
    ans.second = 2 * root->data;
    return ans;
}
bool isSumTree(Node *root)
{
    return sum(root).first;
}