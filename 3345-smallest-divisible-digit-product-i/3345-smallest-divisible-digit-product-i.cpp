class Solution {
public:
    int smallestNumber(int n, int t) {
        int start = n;
        while(true){
            int num = start;
            int res = 1;
            while(num){
                res *= (num%10);
                num /= 10;
            }
            if(res%t == 0) return start;
            start++;
        }
        return -1;
    }
};