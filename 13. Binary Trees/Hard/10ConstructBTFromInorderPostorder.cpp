#include <bits/stdc++.h>
int postorderIndex;
unordered_map<int, int> mapping;
TreeNode *build(vector<int> &postorder, int start, int end)
{
    if (start > end)
        return nullptr;

    int rootVal = postorder[postorderIndex--];
    TreeNode *root = new TreeNode(rootVal);
    int mid = mapping[rootVal];

    root->right = build(postorder, mid + 1, end);
    root->left = build(postorder, start, mid - 1);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    mapping.clear();
    for (int i = 0; i < inorder.size(); i++)
    {
        mapping[inorder[i]] = i;
    }

    postorderIndex = postorder.size() - 1;
    return build(postorder, 0, inorder.size() - 1);
}
