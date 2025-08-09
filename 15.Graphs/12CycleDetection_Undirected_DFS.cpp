#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

bool dfs(unordered_map<int, list<int>> &adjList, vector<bool> &vis, int node, int parent)
{
    vis[node] = true;

    for (auto it : adjList[node])
    {
        if (!vis[it])
        {
            if (dfs(adjList, vis, it, node))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>> &edges)
{
    // Code here
    // adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (dfs(adjList, vis, i, -1))
                return true;
    }
    return false;
}