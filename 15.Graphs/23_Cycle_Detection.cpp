#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    int e = edges.size();

    // Create adjacency list (1-based indexing)
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    { // Fix: Iterate from 0 to e-1
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    // Compute indegrees
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int neighbor : adj[i])
        {
            indegree[neighbor]++;
        }
    }

    // Push 0-indegree nodes into queue
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Perform BFS (Kahn?s Algorithm)
    int cnt = 0;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        cnt++;

        for (int neighbor : adj[frontNode])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // If all nodes are processed, no cycle exists
    return (cnt == n) ? 0 : 1; // 0 = No cycle, 1 = Cycle exists
}
