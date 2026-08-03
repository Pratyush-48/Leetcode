class Solution {
public:
    vector<int>jump = {2,3,4};
    vector<int>curr = {0,1,2};
    int n;
    int recc(int idx,vector<int>&stones,vector<int>&dp){
        if(idx>=n) return 0;
        // take 1,2,3 
        if(dp[idx]!=-1e8) return dp[idx];
        int result = INT_MIN;
        for(auto &it:curr){

            if(it+idx <n){
                int curr = 0;
                for(int i=idx;i<=(idx+it);i++){
                    curr += stones[i];
                }
                int mini = INT_MAX;
                for(auto &it2:jump){
                    mini = min(mini,recc(it+idx+it2,stones,dp));
                }
                curr += mini;
                result = max(result,curr);
            }
        }
        return dp[idx]= result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int>dp(n,-1e8);
        int alice = recc(0,stoneValue,dp);
        int total_sum = accumulate(stoneValue.begin(),stoneValue.end(),0);
        int bob = total_sum - alice;
        if(bob==alice) return "Tie";
        return alice>bob ? "Alice" : "Bob";
    }
};