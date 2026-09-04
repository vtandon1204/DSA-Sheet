#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                      int k)
{
    unordered_map<int, vector<pair<int, int>>> adjList;
    for (int i = 0; i < flights.size(); i++)
    {
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];
        adjList[u].push_back({v, wt});
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<pair<int, pair<int, int>>> q; // {stop,{node,dist}}
    q.push({0, {src, 0}});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int stop = t.first;
        int node = t.second.first;
        int nodeDist = t.second.second;

        if (stop > k)
            continue;

        for (auto it : adjList[node])
        {
            int neigh = it.first;
            int neighDist = it.second;

            int totalDist = neighDist + nodeDist;

            if (totalDist < dist[neigh] && stop <= k)
            {
                dist[neigh] = totalDist;
                q.push({stop + 1, {neigh, totalDist}});
            }
        }
    }
    if (dist[dst] == INT_MAX)
        return -1;
    return dist[dst];
}