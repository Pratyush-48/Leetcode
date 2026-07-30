class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        map<int,int>num;
        for(int i=1;i<=8;i++){
            if(i>=7) num[i] = 2;
            else num[i]=8;
        }
        int result = 0;
        for(auto &it:word){
            freq[it-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int i = 0;
        while(i<26){
            int n = freq[i];
            if(n==0) break;
            auto press = num.begin();
            int p = press->first;
            int c = press->second;
            result += (p*n);
            num[p] = (c-1);
            if(c-1 == 0){
                num.erase(p);
            }
            i++;
        }
        return result;
    }
};