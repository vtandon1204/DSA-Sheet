#include <bits/stdc++.h>
void postorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left, ans);
    // cout << root->data << " ";
    postorder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    // vector<int> ans;
    // if (root == NULL) {
    //     return ans;
    // }
    // vector<int> left = postorderTraversal(root->left);
    // vector<int> right = postorderTraversal(root->right);
    // ans.insert(ans.end(), left.begin(),
    //            left.end()); // Insert left subtree values
    // ans.insert(ans.end(), right.begin(),
    //            right.end()); // Insert right subtree values
    // ans.push_back(root->val);
    // return ans;
    vector<int> ans;
    postorder(root, ans);
    return ans;
}