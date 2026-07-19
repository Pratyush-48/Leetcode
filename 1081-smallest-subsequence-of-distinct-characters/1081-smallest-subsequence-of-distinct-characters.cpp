class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        vector<bool>visited(26,false);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        string ans = "";
        for(int i=0;i<n;i++){
            freq[s[i]-'a']--;
            if(visited[s[i]-'a']) continue;
            while(!ans.empty() && (int)ans.back()>(int)s[i] && freq[ans.back()-'a']>0){
                visited[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            visited[s[i]-'a']=true;
        }
        return ans;
    }
};