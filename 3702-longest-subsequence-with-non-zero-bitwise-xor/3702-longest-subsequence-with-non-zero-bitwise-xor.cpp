class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xo = 0;
        bool non_zero = false;
        for(auto &it:nums){
            xo ^= it;
            if(it>0) non_zero = true;
        }
        if(xo==0 && !non_zero) return 0;
        if(xo==0 && non_zero) return (n-1);
        return n;
    }
};