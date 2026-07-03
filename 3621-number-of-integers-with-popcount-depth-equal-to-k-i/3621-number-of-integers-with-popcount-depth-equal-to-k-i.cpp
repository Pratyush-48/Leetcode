class Solution {
public:
    string s;
    int m;
    long long dp[65][2][2][65];
    int depth[70];
    int target_k;

    long long recc(int idx, bool tight, bool leading_zero, int curr) {
        if(idx >= m) {
            if (curr == 0) return 0; 
            return depth[curr] == target_k - 1 ? 1 : 0;
        }
        
        if(dp[idx][tight][leading_zero][curr] != -1) {
            return dp[idx][tight][leading_zero][curr];
        }
        
        int limit = tight ? (s[idx] - '0') : 1;
        long long result = 0;
        
        for(int i = 0; i <= limit; i++) {
            int n_curr = curr + i;
            bool n_tight = tight && (i == limit);
            bool n_leading_zero = leading_zero && (i == 0);
            
            result += recc(idx + 1, n_tight, n_leading_zero, n_curr);
        }
        
        return dp[idx][tight][leading_zero][curr] = result;
    }

    long long popcountDepth(long long n, int k) {
        if (n == 0) return 0;
        if (k == 0) return 1; 

        depth[1] = 0;
        for (int i = 2; i <= 65; i++) {
            int bits = 0, temp = i;
            while (temp > 0) {
                bits += (temp & 1);
                temp >>= 1;
            }
            depth[i] = 1 + depth[bits];
        }

        target_k = k;
        s = "";
        long long N = n;
        while(N) {
            s += ((N % 2) + '0');
            N /= 2;
        }
        reverse(s.begin(), s.end());
        m = s.length();
        memset(dp, -1, sizeof(dp));
        
        long long ans = recc(0, true, true, 0);
        
        if (k == 1) {
            ans -= 1;
        }
        
        return ans;
    }
};