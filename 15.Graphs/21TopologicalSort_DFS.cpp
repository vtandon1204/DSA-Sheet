#include <bits/stdc++.h> 
void dfsTopoSort(int node, vector<int>&visited, stack<int>&st, unordered_map<int,list<int>>&adj){
    visited[node] = 1;

    for(auto it:adj[node]){
        if(!visited[it]){
            dfsTopoSort(it,visited,st,adj);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adjList
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // topological sort for all components
    vector<int> visited(v,0);
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfsTopoSort(i,visited,st,adj);
        }
    }

    // storing in answer
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}