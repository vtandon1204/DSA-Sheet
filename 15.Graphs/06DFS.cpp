#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &visited, vector<int> &component, int node){
    visited[node] = true;
    component.push_back(node);
    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(adjList, visited, component, i);
        }
    }
}
vector<vector<int>> DFS(int v, int e, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> ans;
    vector<bool> visited(v, false);
    prepareAdjList(adjList, edges);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}