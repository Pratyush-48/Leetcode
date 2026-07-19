class Solution {
public:
    int n;
    vector<vector<int>>pali;
    bool p(int i,int j,string &s){
        if(i>j) return true;
        if(pali[i][j]!=-1) return pali[i][j];
        bool take = s[i]==s[j] && p(i+1,j-1,s);
        pali[i][j] = take;
        p(i+1,j,s);
        p(i,j-1,s);
        return take;
    }
    vector<int>dp;
    int cuts(int idx,string &s){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mini = INT_MAX;
        for(int j=idx;j<n;j++){
            if(pali[idx][j]){
                int curr = 1+cuts(j+1,s);
                mini = min(mini,curr);
            }
        }
        return dp[idx] = mini;
    }
    int minCut(string s) {
        n = s.length();
        pali.resize(n,vector<int>(n,-1));
        dp.resize(n,-1);
        p(0,n-1,s);
        return cuts(0,s)-1;
    }
};