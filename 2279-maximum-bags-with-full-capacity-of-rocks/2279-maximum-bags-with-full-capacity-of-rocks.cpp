class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>diff;
        for(int i=0;i<n;i++){
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(),diff.end());
        int result = 0;
        int i = 0;
        while(i<n && diff[i]==0){
            result++;
            i++;
        }
        for(;i<n;i++){
            if(additionalRocks>=diff[i]){
                additionalRocks -= diff[i];
                result++;
            }
        }
        return result;
    }
};