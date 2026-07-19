class Solution {
public:
    vector<int> comb(vector<int>&arr){
        int n = arr.size();
        int t = pow(2,n) - 1;
        vector<int>result;
        for(int i=0;i<=t;i++){
            int num = i;
            int sum = 0;
            for(int j=0;j<=n;j++){
                if((num&(1<<j)) > 0){
                    sum += arr[j];
                }
            }
            result.push_back(sum);
        }
        sort(result.begin(),result.end());
        return result;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        // divide the array nums in two parts n/2 elements each
        vector<int>arr1;
        vector<int>arr2;
        int n = nums.size()/2;
        int k=0;
        for(auto &it:nums){
            if(k>=n){
                arr2.push_back(it);
            }
            else{
                arr1.push_back(it);
            }
            k++;
        }
        vector<int>arr1_sum = comb(arr1);
        vector<int>arr2_sum = comb(arr2);
        int result = INT_MAX;
        for(auto &it:arr1_sum){
            int t = goal-it;
            auto idx = lower_bound(arr2_sum.begin(),arr2_sum.end(),t);
            if(idx!=arr2_sum.end()){
                int sum = it+*idx;
                result = min(result,abs(sum-goal));
            }
            if(idx!=arr2_sum.begin()){
                idx--;
                int sum = it+*idx;
                result = min(result,abs(sum-goal));
            }
        }
        return result;
    }
};