class Solution {
public:
    int n;
    int dp[101][101][2];
    int recc(int idx,vector<int>&piles,int turn,int m,vector<int>&pref){
        if(idx>=n) return 0;
        if(dp[idx][m][turn]!=-1) return dp[idx][m][turn];
        int result = INT_MAX;
        if(turn==1){
            result = 0;
        }
        for(int x=1;x<=(2*m);x++){
            if(idx + x - 1 >= n) break;
            if(turn==1){
                result = max(result,(pref[idx+x-1]-pref[idx]+piles[idx])+recc(idx+x,piles,0,max(m,x),pref));
            }
            else{
                result = min(result,recc(idx+x,piles,1,max(m,x),pref));
            }
        }
        return dp[idx][m][turn]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<int>pref(n,0);
        pref[0] = piles[0];
        for(int i=1;i<n;i++){
            pref[i] = (pref[i-1]+piles[i]);
        }
        memset(dp,-1,sizeof(dp));
        return recc(0,piles,1,1,pref);
    }
};