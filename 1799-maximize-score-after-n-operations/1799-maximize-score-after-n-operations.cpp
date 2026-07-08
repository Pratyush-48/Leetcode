class Solution {
public:
    typedef long int;
    int N;
    int n;
    int gcd(int a,int b){
        if(b==0) return a;
        if(b>a) return gcd(b,a);
        return gcd(a%b,b);
    }
    unordered_map<string,int>dp;
    int recc(int ops,vector<int>&nums,int selected){
        if(ops>N){
            return 0;
        }
        string key = to_string(ops)+'#'+to_string(selected);
        if(dp.find(key)!=dp.end()) return dp[key];
        int result = 0;
        for(int i=0;i<n;i++){
            if((selected&(1<<i)) != 0) continue;
            for(int j=0;j<n;j++){
                if((selected&(1<<j))!=0 || (i==j)) continue;
                int next_sel = ((selected|(1<<i))|(1<<j));
                result = max(result,ops*gcd(nums[i],nums[j])+recc(ops+1,nums,next_sel));
            }
        }
        return dp[key]=result;
    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        N = n/2;
        return recc(1,nums,0);
    }
};