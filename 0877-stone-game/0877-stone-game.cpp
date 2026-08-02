class Solution {
public:
    int dp[501][501];
    int recc(int i,int j,vector<int>&piles){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i = piles[i] + min(recc(i+2,j,piles),recc(i+1,j-1,piles));
        int take_j = piles[j] + min(recc(i+1,j-1,piles),recc(i,j-2,piles));
        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int total_sum = accumulate(piles.begin(),piles.end(),0);
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        int alice = recc(0,n-1,piles);
        return (alice>(total_sum-alice));
    }
};