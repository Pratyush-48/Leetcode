class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
        }
        int N = temp.size();
        vector<int>t(N);
        for(int i=0;i<N;i++){
            t[(i+k)%N] = temp[i]; 
        }
        k = 0;
        int j = 0;
        for(int i=0;i<N;i++){
            grid[k][j++] = t[i];
            if(j==n){
                k++;
                j = 0;
            }
        }
        return grid;
    }
};