#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<bool> &vis, vector<bool> &pathVis, 
            unordered_map<int,list<int>> &adjList){
        vis[node] = true;
        pathVis[node] = true;
        
        for(auto it:adjList[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adjList)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>> adjList;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
        }
        
        vector<bool> vis(V,false);
        vector<bool> pathVis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adjList)) return true;
            }
        }
        return false;
    }