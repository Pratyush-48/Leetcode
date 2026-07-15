class Solution {
public:
    int findp(int u,vector<int>&parent){
        if(u==parent[u]){
            return u;
        }
        return parent[u] = findp(parent[u],parent);
    }
    void union_by_size(int u,int v,vector<int>&parent,vector<int>&size){
        int u_u = findp(u,parent);
        int u_v = findp(v,parent);
        if(u_u==u_v) return;
        if(size[u_u]>size[u_v]){
            size[u_u]+=size[u_v];
            parent[u_v] = u_u;
        }
        else{
            size[u_v]+=size[u_u];
            parent[u_u] = u_v;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>parent(n,0);
        vector<int>size(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    union_by_size(i,j,parent,size);
                }
            }
        }
        int component = 0;
        for(int i=0;i<n;i++){
            int p = findp(i,parent);
            if(p==i) component++;
        }
        return component;
    }
};