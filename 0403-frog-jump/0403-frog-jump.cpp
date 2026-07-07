class Solution {
public:
    // frog can jump k-1 k k+1 it is soted so it is clearly indicating towards lower_bound to find the idx of the next jump lets start
    int lim = INT_MAX;
    vector<int>dir = {-1,0,1};
    int n;
    unordered_map<string,bool>mp;
    bool jump(int idx,int k,vector<int>&stones){
        if(k==0){
            return idx==n-1;
        }
        if(idx==(n-1)) return true;
        if(idx>n) return false;
        string key = to_string(idx)+'#'+to_string(k);
        if(mp.find(key)!=mp.end()) return mp[key];
        bool res = false;
        int now = stones[idx];
        for(auto &it:dir){
            long next = now + k + it;
            if(next>lim) break;
            auto next_idx = lower_bound(stones.begin(),stones.end(),(int)next);
            if(next_idx!=stones.end() && *next_idx==next){
                int nextt = distance(stones.begin(), next_idx);
                res = res | jump(nextt,k+it,stones);
                if(res){
                    return mp[key] = true;
                }
            }
        }
        return mp[key] = res;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        n = stones.size();
        return jump(1,1,stones);
    }
};