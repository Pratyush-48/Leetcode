class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>freq(101,0);
        for(auto &it:nums) freq[it]++;
        vector<int>result;
        for(int i=mini;i<=maxi;i++){
            if(freq[i]==0) result.push_back(i);
        }
        return result;
    }
};