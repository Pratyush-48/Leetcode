class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;
        map<int,vector<string>>mp;
        int count = 0;
        while(i<n){
            while(count>=k){
                string st = s.substr(i,j-i+1);
                mp[j-i+1].push_back(st);
                count -= s[i]=='1'?1:0;
                i++;
            }
            if(j>=n) break;
            count += s[j]=='1'?1:0;
            j++;
        }
        string st = "";
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
            st = it.second[0];
            break;
        }
        while(!st.empty() && st.back()=='0') st.pop_back();
        return st;
    }
};