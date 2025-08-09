#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (auto it : g)
    {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;
    parent[1] = -1;

    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int node;

        for (int j = 1; j <= n; j++)
        {
            if (!mst[j] && key[j] < mini)
            {
                mini = key[j];
                node = j;
            }
        }
        mst[node] = true;
        for (auto it : adjList[node])
        {
            int neigh = it.first;
            int wt = it.second;
            if (!mst[neigh] && wt < key[neigh])
            {
                key[neigh] = wt;
                parent[neigh] = node;
            }
        }
    }
    vector<pair<pair<int, int>, int>> res;
    for (int i = 2; i <= n; i++)
    {
        res.push_back({{parent[i], i}, key[i]});
    }
    return res;
}
