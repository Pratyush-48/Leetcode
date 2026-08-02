class Solution {
public:
    int dp[301][301];
    int recc(int i,int j,vector<int>&arr){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k=i;k<=j;k++){
            int curr = arr[i-1]*arr[k]*arr[j+1] + recc(i,k-1,arr) + recc(k+1,j,arr);
            maxi = max(maxi,curr);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(1);
        for(auto &it:nums){
            arr.push_back(it);
        }
        arr.push_back(1);
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        return recc(1,n-2,arr);
    }
};