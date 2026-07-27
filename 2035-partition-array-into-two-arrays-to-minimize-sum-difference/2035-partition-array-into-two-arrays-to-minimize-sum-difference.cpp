class Solution {
public:
    void recc(vector<int>&arr,unordered_map<int,vector<long long>>&mp){
        int n = arr.size();
        int m = pow(2,n)-1;
        for(int i=0;i<=m;i++){
            int bits = 0;
            long long sum = 0;
            int num = i;
            for(int j=0;j<n;j++){
                if(num & (1<<j)){
                    bits++;
                    sum += arr[j];
                }
            }
            mp[bits].push_back(sum);
        }
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1;
        vector<int>arr2;
        unordered_map<int,vector<long long>>mp1;
        unordered_map<int,vector<long long>>mp2;
        for(int i=0;i<n;i++){
            if(i<(n/2)){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        recc(arr1,mp1);
        recc(arr2,mp2);
        long long total_sum = accumulate(nums.begin(),nums.end(),0LL);
        long long result = LONG_LONG_MAX;
        long long target = total_sum/2;
        for(auto &it:mp1){
            int bit = it.first;
            int req_bit = (n/2)-bit;
            if(mp2.find(req_bit)!=mp2.end()){
            for(auto &it2:mp1[bit]){
                long long t = target-it2;
                auto it3 = lower_bound(mp2[req_bit].begin(),mp2[req_bit].end(),t);
                if(it3!=mp2[req_bit].end()){
                    long long c_sum = *it3+it2;
                    result = min(result,abs(2*c_sum-total_sum));
                }
                if(it3!=mp2[req_bit].begin()){
                    it3--;
                    long long c_sum = *it3+it2;
                    result = min(result,abs(2*c_sum-total_sum));
                }
            }
            }
        }
        return result;
    }
};