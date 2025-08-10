#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, st);
    }
    st.push(node);
}
void dfs(int node, vector<int> &vis, vector<vector<int>> &revAdj)
{
    vis[node] = 1;
    for (auto it : revAdj[node])
    {
        if (!vis[it])
            dfs(it, vis, revAdj);
    }
}
int kosaraju(vector<vector<int>> &adj)
{
    // code here
    int n = adj.size();
    stack<int> st;
    vector<int> vis(n, 0);

    // perform dfs & prepare the stack
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }

    // reverse the graph
    vector<vector<int>> revAdj(n);
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            revAdj[it].push_back(i);
        }
    }

    // perform dfs again by taking the node from the stack and counting the scc's
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs(node, vis, revAdj);
        }
    }

    return scc;
}