class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        for(auto &it:s){
            freq[it-'a']++;
        }
        vector<char>res(n);
        int j = n-1;
        int k = 0;
        char single = '#';
        for(int i=0;i<26;i++){
            int num = freq[i];
            char ch = i+'a';
            while(num>0){
                if(num==1){
                    single = ch;
                    num -= 1;
                }
                else{
                    res[k] = ch;
                    res[j] = ch;
                    k++;
                    j--;
                    num -= 2;
                }
            }
        }
        if(single!='#'){
            res[k] = single;
        }
        string result = "";
        for(auto &it:res){
            result += it;
        }
        return result;
    }
};