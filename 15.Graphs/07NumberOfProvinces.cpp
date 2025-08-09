#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &visited,
         int node)
{
    visited[node] = true;
    for (auto it : adjList[node])
    {
        if (!visited[it])
            dfs(adjList, visited, it);
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    // DFS
    int n = isConnected.size();
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans++;
            dfs(adjList, visited, i);
        }
    }
    return ans;

    // ***************************************************

    // BFS
    int n = isConnected.size();
    vector<bool> visited(isConnected.size(), false);
    int count = 0;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            q.push(i);
            visited[i] == true;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    if (isConnected[temp][j] == 1 && visited[j] == false)
                    {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    return count;
}