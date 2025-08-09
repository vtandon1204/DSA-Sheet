#include <bits/stdc++.h>
using namespace std;
bool bfs(int i, int n, vector<vector<int>> &graph, vector<int> &color)
{
    queue<int> q;
    q.push(i);
    color[i] = 0;
    while (!q.empty())
    {
        int node = q.front();
        int c = color[node];
        q.pop();
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                color[it] = !c;
                q.push(it);
            }
            else if (color[it] == c)
                return false;
        }
    }
    return true;
}

bool dfs(int node, int c, int n, vector<vector<int>> &graph,
         vector<int> &color)
{
    color[node] = c;
    for (auto it : graph[node])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, !c, n, graph, color))
                return false;
        }
        else if (color[it] == c)
            return false;
    }
    return true;
}


bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    // -1 not color
    // 0 color1
    // 1 color2

    // for (int i = 0; i < n; i++) {
    //     if (color[i] == -1) {
    //         if (!bfs(i, n, graph, color))
    //             return false;
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
            if (!dfs(i, 0, n, graph, color))
                return false;
    }
    return true;
}