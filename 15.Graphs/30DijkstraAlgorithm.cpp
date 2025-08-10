#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    unordered_map<int, vector<pair<int, int>>> adjList;
    set<pair<int, int>> st;
    vector<int> dist(V, INT_MAX);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty())
    {
        auto t = *(st.begin());
        st.erase(st.begin());

        int nodeDistance = t.first;
        int node = t.second;

        for (auto it : adjList[node])
        {
            int neighbour = it.first;
            int neighbourDistance = it.second;

            int totalDistance = nodeDistance + neighbourDistance;

            if (totalDistance < dist[neighbour])
            {
                if (dist[neighbour] != INT_MAX)
                {
                    st.erase({dist[neighbour], neighbour});
                }
                dist[neighbour] = totalDistance;
                st.insert({totalDistance, neighbour});
            }
        }
    }
    return dist;
}

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src, int dest) {
    unordered_map<int, vector<pair<int, int>>> adjList;
    set<pair<int, int>> st;
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1); // Track parent for path reconstruction

    // Build adjacency list
    for (auto &e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto [nodeDistance, node] = *st.begin();
        st.erase(st.begin());

        for (auto [neighbour, wt] : adjList[node]) {
            int totalDistance = nodeDistance + wt;
            if (totalDistance < dist[neighbour]) {
                if (dist[neighbour] != INT_MAX) {
                    st.erase({dist[neighbour], neighbour});
                }
                dist[neighbour] = totalDistance;
                parent[neighbour] = node; // Store parent
                st.insert({totalDistance, neighbour});
            }
        }
    }

    // Reconstruct the path from src to dest
    vector<int> path;
    if (dist[dest] == INT_MAX) {
        cout << "No path exists\n";
        return {};
    }

    for (int at = dest; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    // Print distance and path
    cout << "Shortest Distance from " << src << " to " << dest << " = " << dist[dest] << "\n";
    cout << "Path: ";
    for (int node : path) cout << node << " ";
    cout << "\n";

    return path;
}