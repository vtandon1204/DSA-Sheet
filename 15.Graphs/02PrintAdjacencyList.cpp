#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
{
    // Adjacency list to store the graph
    vector<vector<int>> adjacent(V);

    // Fill the adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    // Resulting adjacency list
    vector<vector<int>> adjList(V);

    // Copy the adjacency list structure
    for (int i = 0; i < V; i++)
    {
        // adjList[i].push_back(i);  // Optional: include the node itself as the first element
        for (int j = 0; j < adjacent[i].size(); j++)
        {
            adjList[i].push_back(adjacent[i][j]);
        }
    }

    return adjList;
}