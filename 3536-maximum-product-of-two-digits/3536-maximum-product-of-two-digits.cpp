class Solution {
public:
    int maxProduct(int n) {
        vector<int>freq(10,0);
        while(n){
            int d = n%10;
            n/=10;
            freq[d]++;
        }
        int result = 0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(i==j){
                    if(freq[i]>=2){
                        result = max(result,i*i);
                    }
                }
                    else{
                        if(freq[i]!=0 && freq[j]!=0){
                            result = max(result,i*j);
                        }
                    }
            }
        }
        return result;
    }
};