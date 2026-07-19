class Solution {
public:
    int n;
    vector<vector<bool>>pali;
    vector<vector<int>>dp;
    bool recc(int i,int j,string &s){
        if(i>j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool check = s[i]==s[j] && recc(i+1,j-1,s);
        pali[i][j] = check;
        recc(i+1,j,s);
        recc(i,j-1,s);
        return dp[i][j] = check;
    }
    vector<int>t;
    int cut(int i,string&s){
        if(i>=n) return 0;
        if(t[i]!=-1) return t[i];
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            if(pali[i][j]){
                int curr = 1+cut(j+1,s);
                mini = min(mini,curr);
            }
        }
        return t[i] = mini;
    }
    int minCut(string s) {
        n = s.length();
        pali.resize(n,vector<bool>(n,false));
        dp.resize(n,vector<int>(n,-1));
        recc(0,n-1,s);
        t.resize(n,-1);
        return cut(0,s)-1;
    }
};