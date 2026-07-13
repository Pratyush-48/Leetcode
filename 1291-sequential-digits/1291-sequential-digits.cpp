class Solution {
public:
    vector<int>ans;
    void recc(int low,int high,long num,int prev){
        if(num>high) return;
        if(num>=low && num<=high){
            ans.push_back(num);
        }
        if(prev+1 >= 10) return;
        long next_num = (num*10)+(prev+1);
        recc(low,high,next_num,prev+1);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=0;i<=9;i++){
            recc(low,high,0,i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};