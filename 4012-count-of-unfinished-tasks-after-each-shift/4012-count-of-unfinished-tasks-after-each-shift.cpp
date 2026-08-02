class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();
        vector<long long>pref(n,0);
        pref[0] = tasks[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+tasks[i];
        }
        // prefix toh sorted rahega
        long long prev = 0;
        int i = 0;
        vector<int>ans(m,0);
        while(i<m){
            long long curr = prev + shifts[i];
            if(curr>=pref.back()){
                prev = 0;
            }
            else{
                int idx = upper_bound(pref.begin(),pref.end(),curr)-pref.begin();
                ans[i] = n-idx;
                prev = curr;
            }
            i++;
        }
        return ans;
    }
};