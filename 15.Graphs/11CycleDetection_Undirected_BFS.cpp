#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

bool bfs(unordered_map<int, list<int>> &adjList, vector<bool> &vis, int node)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    vis[node] = true;

    while (!q.empty())
    {
        int frontNode = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adjList[frontNode])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push({it, frontNode});
            }
            else if (it != parent)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>> &edges)
{
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
            if (bfs(adjList, vis, i))
                return true;
    }
    return false;
}