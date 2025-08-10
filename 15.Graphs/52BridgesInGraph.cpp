#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int timer, unordered_map<int, list<int>> &adjList,
         vector<int> &time, vector<int> &low, vector<int> &vis,
         vector<vector<int>> &ans)
{
    vis[node] = 1;
    time[node] = low[node] = timer;
    timer++;
    for (auto it : adjList[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, timer, adjList, time, low, vis, ans);
            // update low
            low[node] = min(low[node], low[it]);
            // check bridge
            if (time[node] < low[it])
            {
                ans.push_back({node, it});
            }
        }
        else
        {
            // if it's already visited, it cannot be a bridge
            // just update the low
            low[node] = min(low[node], low[it]);
        }
    }
}
vector<vector<int>> criticalConnections(int n,
                                        vector<vector<int>> &connections)
{
    unordered_map<int, list<int>> adjList(n);

    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> time(n), low(n), vis(n, 0);

    vector<vector<int>> ans;
    dfs(0, -1, 1, adjList, time, low, vis, ans);
    return ans;
}