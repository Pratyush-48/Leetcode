class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int i = 0;
        int j = 0;
        int n = intervals.size();
        while(i<n){
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c = intervals[j][0];
            int d = intervals[j][1];
            while(j<n && a<=c && d<=b){
                j++;
                if(j<n){
                    c = intervals[j][0];
                    d = intervals[j][1];
                }
            }
            i = j;
            result++;
        }
        return result;
    }
};