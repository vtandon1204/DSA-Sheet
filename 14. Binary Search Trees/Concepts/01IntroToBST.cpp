#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBSTTraversal(vector<int> &arr)
{
    // inorder traversal of a BST is a sorted array
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

TreeNode *insertNode(TreeNode *root, int data)
{
    // base case
    if (!root)
    {
        root = new TreeNode(data);
        return root;
    }
    if (root->val < data)
    {
        // insertNode at right
        root->right = insertNode(root->right, data);
    }
    else
    {
        // insertNode at left
        root->left = insertNode(root->left, data);
    }
    return root;
}

TreeNode *maxElementFromLeftSubtree(TreeNode *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}
TreeNode *deleteNode(TreeNode *root, int data)
{
    if (!root)
        return NULL;
    if (root->val == data)
    {
        // 0 child
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // 1 child - left
        if (root->left && !root->right)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // 1 child - right
        if (!root->left && root->right)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        if (root->left && root->right)
        {
            int maxFromLeft = maxElementFromLeftSubtree(root->left)->val;
            root->val = maxFromLeft;
            root->left = deleteNode(root->left, maxFromLeft);
            return root;
        }
    }
    else if (root->val > data)
    {
        root->left = deleteNode(root->left, data);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, data);
        return root;
    }
}
TreeNode *arrayToBST(vector<int> arr)
{
    int n = arr.size();
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insertNode(root, arr[i]);
    }
    return root;
}

// In-order traversal to print BST
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    vector<int> arr = {5, 3, 8, 1, 4, 7, 9};
    TreeNode *root = arrayToBST(arr);
    root = insertNode(root, 2);
    cout << "In-order Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}