class Solution {
public:
    typedef tuple<int,int,int> t;
    vector<int>parent;
    vector<int>size;
    int findp(int u){
        if(u==parent[u]) return u;
        return parent[u] = findp(parent[u]);
    }
    void union_by(int u,int v){
        int u_u = findp(u);
        int u_v = findp(v);
        if(u_u==u_v)return;
        if(size[u_u]>size[u_v]){
            size[u_u] += size[u_v];
            parent[u_u] = u_v;
        }
        else{
            size[u_v] += size[u_u];
            parent[u_v] = u_u;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
        unordered_map<int,vector<vector<int>>>adj;
        for(auto &it:roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            union_by(u,v);
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int p = -1;
        int mini = INT_MAX;
        for(int i=0;i<=n;i++){
            int u_p = findp(i);
            if(i==1){
                p = u_p;
            }
            if(u_p==p){
                for(auto &it:adj[i]){
                    mini = min(mini,it[1]);
                }
            }
        }
        return mini;
    }
};