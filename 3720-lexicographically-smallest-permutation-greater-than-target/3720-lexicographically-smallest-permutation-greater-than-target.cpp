class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int> mp;
        for(char ch : s) {
            mp[ch]++;
        }
        
        int n = s.length();
        int match_len = 0;
        
        // STEP 1: Greedily match prefix
        for(int i = 0; i < n; i++) {
            if(i >= target.length()) break; 
            
            // Check agar character strictly available hai
            if(mp.find(target[i]) != mp.end()) {
                mp[target[i]]--;
                // CRUCIAL FIX: Remove from map if count reaches 0
                if(mp[target[i]] == 0) {
                    mp.erase(target[i]);
                }
                match_len++;
            } else {
                break; 
            }
        }
        
        // STEP 2: Backtrack to find a strictly greater character
        for(int i = match_len; i >= 0; i--) {
            
            if (i < target.length()) {
                auto it = mp.upper_bound(target[i]);
                // Kyunki hum zero walo ko erase kar rahe hain, it->first 100% available hai
                if(it != mp.end()) {
                    char ch = it->first;
                    
                    string result = target.substr(0, i) + ch;
                    mp[ch]--; 
                    // Yahan erase karna zaruri nahi hai kyunki aage map ko modify nahi karna, 
                    // par consistency ke liye kar sakte hain.
                    if(mp[ch] == 0) mp.erase(ch);
                    
                    // Bachi hui string ko append kardo
                    for(auto& p : mp) {
                        // Ab p.second kabhi negative nahi hoga
                        result += string(p.second, p.first); 
                    }
                    
                    return result; 
                }
            }
            
            // Backtrack logic: Restore the character we just gave up
            if (i > 0) {
                mp[target[i-1]]++;
            }
        }
        
        return ""; 
    }
};