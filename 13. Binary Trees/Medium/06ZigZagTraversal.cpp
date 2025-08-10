#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
};

vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            int index = leftToRight ? i : (n - 1 - i);
            // int index;
            // if(leftToRight){
            //     index = i;
            // }
            // else{
            //     index = n-1-i;
            // }
            temp[index] = node->val;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        ans.push_back(temp);
    }
    return ans;
}