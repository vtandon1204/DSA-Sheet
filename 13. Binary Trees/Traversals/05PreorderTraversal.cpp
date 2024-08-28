#include <bits/stdc++.h>
void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->val);
    preorder(root->left, ans);
    // cout << root->data << " ";
    preorder(root->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
    // vector<int> ans;
    // if(!root){
    //     return ans;
    // }
    // stack<TreeNode*> st;
    // st.push(root);
    // while(!st.empty()){
    //     root = st.top();
    //     st.pop();
    //     ans.push_back(root->val);
    //     if(root->right){
    //         st.push(root->right);
    //     }
    //     if(root->left){
    //         st.push(root->left);
    //     }
    // }
    // return ans;
    // *******************************************************
    // vector<int> ans;
    // if (root == NULL) {
    //     return ans;
    // }
    // vector<int> left = preorderTraversal(root->left);
    // vector<int> right = preorderTraversal(root->right);
    // ans.push_back(root->val);
    // ans.insert(ans.end(), left.begin(),
    //            left.end()); // Insert left subtree values
    // ans.insert(ans.end(), right.begin(),
    //            right.end()); // Insert right subtree values
    // return ans;
    // *******************************************************
    vector<int> ans;
    preorder(root, ans);
    return ans;
}