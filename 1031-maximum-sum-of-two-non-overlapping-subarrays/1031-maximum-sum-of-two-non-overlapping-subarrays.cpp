class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int result = 0;
        int n = nums.size();
        vector<int>pref_sum(n,0);
        pref_sum[0] = nums[0];
        for(int i=1;i<n;i++){
            pref_sum[i] = nums[i]+pref_sum[i-1];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int st1 = i;
                int end1 = i+firstLen-1;
                int st2 = j;
                int end2 = j+secondLen-1;
                if(end1<n && end2<n && (st1>end2 || st2>end1)){
                    result = max(result,(pref_sum[end1]-pref_sum[st1]+nums[st1]+(pref_sum[end2]-pref_sum[st2]+nums[st2])));
                }
            }
        }
        return result;
    }
};