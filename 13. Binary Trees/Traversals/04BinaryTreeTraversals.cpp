#include <bits/stdc++.h>
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    ans.push_back(root->data);
    ans.insert(ans.end(), left.begin(),
               left.end()); // Insert left subtree values
    ans.insert(ans.end(), right.begin(),
               right.end()); // Insert right subtree values
    return ans;
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    vector<int> left = inorderTraversal(root->left);
    vector<int> right = inorderTraversal(root->right);
    ans.insert(ans.end(), left.begin(),
               left.end()); // Insert left subtree values
    ans.push_back(root->data);
    ans.insert(ans.end(), right.begin(),
               right.end()); // Insert right subtree values
    return ans;
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    vector<int> left = postorderTraversal(root->left);
    vector<int> right = postorderTraversal(root->right);
    ans.insert(ans.end(), left.begin(),
               left.end()); // Insert left subtree values
    ans.insert(ans.end(), right.begin(),
               right.end()); // Insert right subtree values
    ans.push_back(root->data);
    return ans;
}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<vector<int>> ans;
    ans.push_back(inorderTraversal(root));
    ans.push_back(preorderTraversal(root));
    ans.push_back(postorderTraversal(root));
    return ans;
}