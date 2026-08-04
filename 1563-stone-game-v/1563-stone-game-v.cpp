class Solution {
public:
    int dp[505][505];
    int recc(int idx,int r,vector<int>&stone,vector<int>&pref){
        if(idx>=r) return 0;
        if(dp[idx][r]!=-1) return dp[idx][r];
        int maxi = INT_MIN;
        for(int i=idx;i<r;i++){
            int l = pref[i]-pref[idx]+stone[idx];
            int rr = pref[r]-pref[i];
            int curr;
            if(l>rr){
                curr = rr+recc(i+1,r,stone,pref);
            }
            if(l<rr){
                curr = l+recc(idx,i,stone,pref);
            }
            if(l==rr){
                curr = max(l+recc(idx,i,stone,pref),rr+recc(i+1,r,stone,pref));
            }
            maxi = max(maxi,curr);
        }
        return dp[idx][r] = maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp,-1,sizeof(dp));
        vector<int>pref(n,0);
        pref[0] = stoneValue[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+stoneValue[i];
        }
        return recc(0,n-1,stoneValue,pref);
    }
};