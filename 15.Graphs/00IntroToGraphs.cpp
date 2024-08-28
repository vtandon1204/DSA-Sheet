#include <bits/stdc++.h>
using namespace std;
// 1. Adjacency Matrix
// if row_element connected to col_element --> 1
// if not --> 0
// Space Complexity --> O(n^2) --> 2D matrix

// 2. Adjacency List
// map<int, list<int>>
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " --> ";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<int> adjacent[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    vector<vector<int>> adjList[n];
    for (int i = 0; i < n; i++)
    {
        adjList[i].push_back(i);
        for (int j = 0; j < mj++)
        {
            adjList[i].push_back(adjacent[i][j]);
        }
    }
    return adjList;
}
int main()
{
    int n;
    int m;
    cout << "enter the number of nodes ";
    cin >> n;
    cout << "enter the number of edges ";
    cin >> m;

    Graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }
    g.printAdjList();
}