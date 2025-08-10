#include <bits/stdc++.h>
using namespace std;

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(vector<vector<int>> &dist)
{
    int n = dist.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == -1)
                dist[i][j] = 1e8;
            if (i == j)
                dist[i][j] = 0;
        }
    }
    // Add all vertices one by one to
    // the set of intermediate vertices.
    for (int k = 0; k < n; k++)
    {

        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++)
        {

            // Pick all vertices as destination
            // for the above picked source
            for (int j = 0; j < n; j++)
            {

                // shortest path from
                // i to j
                if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // check negative cycle
    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
            cout << "negative cycle present\n";
    }
}