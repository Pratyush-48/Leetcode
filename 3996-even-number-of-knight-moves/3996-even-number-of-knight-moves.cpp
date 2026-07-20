class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        vector<vector<int>>dir={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        int n = 64;
        if(start==target) return true;
        vector<vector<bool>>visit(64,vector<bool>(64,false));
        queue<pair<int,pair<int,int>>>q;
        visit[start[0]][start[1]] = true;
        q.push({0,{start[0],start[1]}});
        while(!q.empty()){
            int x = q.front().second.first;
            int y = q.front().second.second;
            int val = q.front().first;
            q.pop();
            for(auto &it:dir){
                int nx = x + it[0];
                int ny = y + it[1];
                if(nx==target[0] && ny==target[1] ){
                    if((val+1)%2 == 0) return true;
                    continue;
                }
                if(nx>=0 && nx<n && ny>=0 && ny<n && !visit[nx][ny]){
                    visit[nx][ny] = true;
                    q.push({(val+1)%2,{nx,ny}});
                }
            }
        }
        return false;
    }
};