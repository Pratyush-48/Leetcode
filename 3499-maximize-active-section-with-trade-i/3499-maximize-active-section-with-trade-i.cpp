class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<pair<int,int>>vec;
        int ac = 0;
        for(int i=0;i<n;){
            int j = i;
            while(j<n && s[i]==s[j]){
                if(s[j]=='1') ac++;
                j++;
            }
            vec.push_back({s[i]-'0',j-i});
            i = j;
        }
        int m  = vec.size();
        int result = ac;
        for(int i=0;i<m;i++){
            if(vec[i].first==1 && i>0 && i+1<m){
                result = max(result,ac+vec[i-1].second+vec[i+1].second);
            }
        }
        return result;
    }
};