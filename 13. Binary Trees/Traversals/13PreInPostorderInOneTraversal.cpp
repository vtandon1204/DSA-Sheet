#include <bits/stdc++.h>
vector<vector<int>> preInPostTraversal(Node *root)
{
    if (!root)
    {
        return {};
    }
    vector<int> pre, in, post;
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->left)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if (it.first->right)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->val);
        }
    }
    vector<vector<int>> ans;
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}