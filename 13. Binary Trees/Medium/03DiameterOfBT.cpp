#include <bits/stdc++.h>
// int height(Node *root)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     int h1 = height(root->left);
//     int h2 = height(root->right);
//     return max(h1, h2) + 1;
// }
int heightAndDiameter(Node *root, int &diameter)
{
    if (!root)
    {
        return 0;
    }

    // Recursively get the heights of left and right subtrees
    int leftHeight = heightAndDiameter(root->left, diameter);
    int rightHeight = heightAndDiameter(root->right, diameter);

    // Calculate the diameter at the current node
    int currentDiameter = leftHeight + rightHeight + 1;

    // Update the maximum diameter found so far
    diameter = max(diameter, currentDiameter);

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
}

int diameter(Node *root)
{
    // if(!root){
    //     return 0;
    // }
    // int op1 = diameter(root->left);
    // int op2 = diameter(root->right);
    // int op3 = height(root->left)+height(root->right)+1;
    // int ans = max(op3,max(op1,op2));
    // return ans;
    int diameter = 0;
    heightAndDiameter(root, diameter);
    return diameter;
}
// **********************************************************************
pair<int, int> diameterFast(Node *root)
{
    if (!root)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    // first --> diameter & second --> height
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(Node *root)
{
    return diameterFast(root).first;
}