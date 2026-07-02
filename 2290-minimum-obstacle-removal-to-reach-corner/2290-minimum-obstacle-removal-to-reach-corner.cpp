class Solution {
public:
    typedef tuple<int,int,int> t;
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<t,vector<t>,greater<t>>mh;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        mh.push({0,0,0});
        dist[0][0] = 0;
        while(!mh.empty()){
            auto [walls,i,j] = mh.top();
            mh.pop();
            if(i==m-1 && j==n-1) return walls;
            for(auto &d:dir){
                int n_i = i+d[0];
                int n_j = j+d[1];
                if(n_i>=0 && n_i<m && n_j>=0 && n_j<n && (dist[n_i][n_j]>(walls+grid[n_i][n_j]))){
                    mh.push({walls+grid[n_i][n_j],n_i,n_j});
                    dist[n_i][n_j] = walls+grid[n_i][n_j];
                }
            }
        }
        return -1;
    }
};