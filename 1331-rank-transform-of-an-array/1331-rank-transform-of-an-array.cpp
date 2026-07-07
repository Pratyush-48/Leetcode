class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        int res = 1;
        vector<int>result(n,0);
        for(auto &it:mp){
            for(auto &idx:it.second){
                result[idx] = res;
            }
            res++;
        }
        return result;
    }
};