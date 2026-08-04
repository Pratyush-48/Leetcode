class Solution {
public:
    int n;
    int dp[101][101];
    int recc(int idx,int m,vector<int>&piles,vector<int>&pref){
        if(idx>=n) return 0;
        if(dp[idx][m]!=-1) return dp[idx][m];
        int maxi = INT_MIN;
        int N = min(n, idx + 2 * m);
        for(int i=idx;i<N;i++){
            int curr = pref[i]-pref[idx]+piles[idx];
            int rem = i-idx+1;
            int next_m = max(m,rem);
            int mini = INT_MAX;
            if(i+1>=n) mini = 0;
            int bob_limit = min(n, (i + 1) + 2 * next_m);
            for(int j=i+2;j<=bob_limit;j++){
                int y = j-i-1;
                mini = min(mini,recc(j,max(next_m,y),piles,pref));
            }
            maxi = max(maxi,curr+mini);
        }
        return dp[idx][m]=maxi;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<int>pref(n,0);
        pref[0] = piles[0];
        for(int i=1;i<n;i++){
            pref[i] = piles[i] + pref[i-1];
        }
        memset(dp,-1,sizeof(dp));
        return recc(0,1,piles,pref);
    }
};