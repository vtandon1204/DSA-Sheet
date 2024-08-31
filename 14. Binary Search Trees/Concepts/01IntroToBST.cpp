#include <bits/stdc++.h>
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