#include <bits/stdc++.h>
// Balanced Tree --> abs(height(left) - height(right)) <= 1
// int height(struct Node* node){
//     // base case
//     if(!node){
//         return 0;
//     }
//     int h1 = height(node->left);
//     int h2 = height(node->right);

//     int ans = max(h1,h2)+1;
//     return ans;
// }
pair<bool, int> isBalancedFast(Node *root)
{
    if (!root)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    // ans.first = leftAns&&rightAns&&diff;
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
// Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    // if(!root){
    //     return true;
    // }
    // bool left = isBalanced(root->left);
    // bool right = isBalanced(root->right);
    // bool diff = abs(height(root->left) - height(root->right)) <= 1;
    // if(left&&right&&diff){
    //     return true;
    // }
    // else{
    //     return false;
    // }
    return isBalancedFast(root).first;
}
// ***************************************************************************
bool isBalanced(Node *root)
{
    // Check if the tree's height difference
    // between subtrees is less than 2
    // If not, return false; otherwise, return true
    return dfsHeight(root) != -1;
}

// Recursive function to calculate
// the height of the tree
int dfsHeight(Node *root)
{
    // Base case: if the current node is NULL,
    // return 0 (height of an empty tree)
    if (root == NULL)
        return 0;

    // Recursively calculate the
    // height of the left subtree
    int leftHeight = dfsHeight(root->left);

    // If the left subtree is unbalanced,
    // propagate the unbalance status
    if (leftHeight == -1)
        return -1;

    // Recursively calculate the
    // height of the right subtree
    int rightHeight = dfsHeight(root->right);

    // If the right subtree is unbalanced,
    // propagate the unbalance status
    if (rightHeight == -1)
        return -1;

    // Check if the difference in height between
    // left and right subtrees is greater than 1
    // If it's greater, the tree is unbalanced,
    // return -1 to propagate the unbalance status
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    // Return the maximum height of left and
    // right subtrees, adding 1 for the current node
    return max(leftHeight, rightHeight) + 1;
}