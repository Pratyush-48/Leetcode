class Solution {
public:
    bool bfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        int edge_count=0;
        queue<int>q;
        visited[node]=true;
        q.push(node);
        int node_count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            node_count++;
            edge_count+=adj[curr].size();
        for(auto neigh:adj[curr]){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh]=true;
            }
        }
        }
        edge_count/=2;
        return (edge_count == (node_count*(node_count-1)/2));
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // create adj list
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        int result = 0;
        for(int i=0;i<n;i++){
        if(!visited[i]){
            if(bfs(i,adj,visited)){
                result++;
            }
        }
        }
        return result;
    }
};