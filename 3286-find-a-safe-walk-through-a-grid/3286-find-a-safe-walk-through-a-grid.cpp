class Solution {
public:
    typedef tuple<int,int,int> t;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<t>mh;
        mh.push({health-grid[0][0],0,0});
        vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>>dist(m,vector<int>(n,INT_MIN));
        dist[0][0] = health-grid[0][0];
        while(!mh.empty()){
            auto [h,i,j] = mh.top();
            mh.pop();
            if(i==m-1 && j==n-1 && h>=1) return true;
            for(auto &it:dir){
                int n_i = i+it[0];
                int n_j = j+it[1];
                if(n_i>=0 && n_i<m && n_j>=0 && n_j<n && dist[n_i][n_j]<(h-grid[n_i][n_j])){
                    mh.push({h-grid[n_i][n_j],n_i,n_j});
                    dist[n_i][n_j] = h-grid[n_i][n_j];
                }
            }
        }
        return false;
    }
};