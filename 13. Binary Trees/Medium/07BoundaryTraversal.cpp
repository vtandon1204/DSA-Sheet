#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
bool isLeaf(Node *node)
{
    if (!node->left && !node->right)
    {
        return true;
    }
    return false;
}
void addLeftBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            ans.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void addLeaves(Node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeaves(root->left, ans);
    }
    if (root->right)
    {
        addLeaves(root->right, ans);
    }
}
void addRightBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root->right;
    vector<int> rev;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            rev.push_back(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = rev.size() - 1; i >= 0; i--)
    {
        ans.push_back(rev[i]);
    }
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
}