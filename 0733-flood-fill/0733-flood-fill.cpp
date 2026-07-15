class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int m = image.size();
        int n = image[0].size();
        int i = image[sr][sc];
        if(i==color) return image;
        image[sr][sc] = color;
        vector<vector<int>>dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto &it:dir){
                int n_r = r+it[0];
                int n_c = c+it[1];
                if(n_r<m && n_r>=0 && n_c<n && n_c>=0 && image[n_r][n_c]==i){
                    image[n_r][n_c] = color;
                    q.push({n_r,n_c});
                }
            }
        }
        return image;
    }
};