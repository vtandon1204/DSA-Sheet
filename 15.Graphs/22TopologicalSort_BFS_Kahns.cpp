#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>>& adj) {

    // find indegree
    int v = adj.size();
    vector<int> indegree(v);

    for (int i = 0; i < v; i++) {  
        for (int j : adj[i]) {
            indegree[j]++;
        }
    }

    // push 0-indegree elements into queue
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    } 

    // do BFS
    vector<int> ans;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i : adj[frontNode]){
            indegree[i]--;
            if(!indegree[i]){
                q.push(i);
            }
        }
    }
    return ans;
}