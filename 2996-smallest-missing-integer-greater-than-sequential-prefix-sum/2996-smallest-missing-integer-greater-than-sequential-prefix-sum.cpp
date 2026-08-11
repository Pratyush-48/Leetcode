class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        set<int>st(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]!=nums[i-1]+1) break;
            sum += nums[i];
        }
        while(true){
            if(st.find(sum)==st.end()) return sum;
            sum++;
        }
        return -1;
    }
};