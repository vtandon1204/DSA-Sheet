#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    unordered_map<int, vector<pair<int, int>>> adjList;
    for (auto t : times)
    {
        int u = t[0], v = t[1], wt = t[2];
        adjList[u].push_back({v, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, k});

    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        int time = t.first;
        int node = t.second;
        if (time > dist[node])
            continue;

        for (auto &[neighbor, wt] : adjList[node])
        {
            if (time + wt < dist[neighbor])
            {
                dist[neighbor] = time + wt;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    int ans = *max_element(dist.begin() + 1, dist.end());
    return (ans == INT_MAX) ? -1 : ans;
}