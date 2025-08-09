#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<pair<int, int>>> &adjList, vector<bool> &vis, stack<int> &st)
{
    vis[node] = true;

    for (auto it : adjList[node])
    {
        if (!vis[it.first])
        {
            dfs(it.first, adjList, vis, st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    // code here
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
    }
    vector<bool> vis(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adjList, vis, st);
        }
    }
    vector<int> dist(V, INT_MAX);
    int src = 0;
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        int nodeDist = dist[node];
        if (dist[node] != INT_MAX)
        {
            for (auto it : adjList[node])
            {
                int neigh = it.first;
                int neighDist = it.second;
                if (nodeDist + neighDist < dist[neigh])
                {
                    dist[neigh] = neighDist + nodeDist;
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
}