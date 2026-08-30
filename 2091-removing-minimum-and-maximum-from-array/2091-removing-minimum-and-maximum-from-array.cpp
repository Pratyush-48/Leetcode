class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        auto it = max_element(nums.begin(),nums.end());
        auto jt = min_element(nums.begin(),nums.end());
        int i = it-nums.begin();
        int j = jt-nums.begin();
        int xi = min(i,j);
        int xj = max(i,j);
        if(xi==xj){
            return min(n-xi,xi+1);
        }
        int res = xi+1 + n-xj;
        res = min(res,xi+1+(xj-xi));
        res = min(res,n-xj+(xj-xi));
        res = min(res,n-xj+xi+1);
        return res;
    }
};