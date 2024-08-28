#include <bits/stdc++.h>
void inorder(BinaryTreeNode<int> *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inorder(root->right, count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    int ans = 0;
    inorder(root, ans);
    return ans;
}