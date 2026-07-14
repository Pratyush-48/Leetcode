class Solution {
public:
    long mod = 1e9 + 7;
    int n;
    long gcd(long a,long b){
        if(b==0){
            return a;
        }
        if(a<b){
            return gcd(b,a);
        }
        return gcd(a%b,b);
    }
    long dp[201][201][201];
    long recc(int idx,long seq1,long seq2,vector<int>&nums){
        if(idx>=n){
            return (seq1>0 && seq1==seq2);
        }
        if(dp[idx][seq1][seq2]!=-1) return dp[idx][seq1][seq2];
        // in seq1
        long long take_1 = recc(idx+1,gcd(seq1,(long)nums[idx]),seq2,nums);
        // in seq2
        long long take_2 = recc(idx+1,seq1,gcd(seq2,(long)nums[idx]),nums);
        // dont take
        long long dont_take = recc(idx+1,seq1,seq2,nums);
        return dp[idx][seq1][seq2]=(take_1+take_2+dont_take)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return recc(0,0,0,nums)%mod;
    }
};