void dfs()
vector<int> shortestPath(vector<pair<int, pair<int,int>>> edges, int n, int m, int s)
{
    // n -> number of nodes
    // m -> number of edges
    // s -> source node
    // edges -> vector of pairs of edges

    // create adj list
    unordered_map<int, list<pair<int,int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // required data structures
    vector<bool> visited(n, false);
    stack<int> st;

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