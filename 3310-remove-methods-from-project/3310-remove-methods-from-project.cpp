class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int node,vector<int>&visit){
        visit[node] = 1;
        for(auto &it:adj[node]){
            if(!visit[it]){
                dfs(adj,it,visit);
            }
        }
    }
    int reach = 0;
    void bfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&visit,vector<int>&visit2){
        queue<int>q;
        q.push(node);
        visit2[node] = 1;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(auto &it:adj[n]){
                if(visit[it]) reach = 1;
                if(!visit2[it]){
                q.push(it);
                visit2[it] = 1;
                }
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>visit(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto &it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        dfs(adj,k,visit);
        reach = 0;
        vector<int>result;
        vector<int>visit2 = visit;
        for(int i=0;i<n;i++){
            if(!visit[i]) result.push_back(i);
            if(!visit2[i] && !visit[i]){
                bfs(i,adj,visit,visit2);
            }
            if(reach){
            vector<int>res;
            for(int i=0;i<n;i++){
                res.push_back(i);
            }
            return res;
            }
        }

        return result;
    }
};