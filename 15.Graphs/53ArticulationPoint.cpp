#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> adj[], vector<int> &vis, vector<int> &tim,
         vector<int> &low, vector<int> &mark)
{
    vis[node] = 1;
    tim[node] = low[node] = timer;
    timer++;
    int child = 0;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, timer, adj, vis, tim, low, mark);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tim[node] && parent != -1)
            {
                mark[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tim[it]);
        }
    }
    if (child > 1 && parent == -1)
    {
        mark[node] = 1;
    }
}
vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> tim(V), low(V);
    vector<int> mark(V, 0);
    int timer = 1;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, timer, adj, vis, tim, low, mark);
        }
    }
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (mark[i] == 1)
            ans.push_back(i);
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}