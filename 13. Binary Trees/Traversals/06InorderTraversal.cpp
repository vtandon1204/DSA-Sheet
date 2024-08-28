#include <bits/stdc++.h>
void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    // cout << root->data << " ";
    ans.push_back(root->val);
    inorder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode *root)
{
    // vector<int> ans;
    // if(!root){
    //     return ans;
    // }
    // stack<TreeNode*> st;
    // TreeNode* node = root;
    // while(true){
    //     if(node){
    //         st.push(node);
    //         node = node->left;
    //     }
    //     else{
    //         if(st.empty()){
    //             break;
    //         }
    //         node = st.top();
    //         st.pop();
    //         ans.push_back(node->val);
    //         node = node->right;
    //     }
    // }
    // return ans;
    // *******************************************************
    // vector<int> ans;
    // if (root == NULL) {
    //     return ans;
    // }
    // vector<int> left = inorderTraversal(root->left);
    // vector<int> right = inorderTraversal(root->right);
    // ans.insert(ans.end(), left.begin(),
    //            left.end()); // Insert left subtree values
    // ans.push_back(root->val);
    // ans.insert(ans.end(), right.begin(),
    //            right.end()); // Insert right subtree values
    // return ans;
    // *******************************************************
    vector<int> ans;
    inorder(root, ans);
    return ans;
}