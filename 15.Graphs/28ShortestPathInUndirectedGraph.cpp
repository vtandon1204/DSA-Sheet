vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // n -> number of nodes
    // m -> number of edges
    // s -> source node
    // t -> target node
    // edges -> vector of pairs of edges

    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // required data structures
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }

    // if target node is not reachable from source node
    if (parent[t] == -1)
        return {-1};

    // if target node is reachable from source node
    // then we need to backtrack the path from target node to source node
    // and return the path in reverse order
    vector<int> path;
    int curr = t;
    while (curr != s)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}