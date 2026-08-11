class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(discounts.rbegin(),discounts.rend());
        sort(prices.rbegin(),prices.rend());
        int n = prices.size();
        int m = discounts.size();
        double result = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            double curr = prices[i];
            if(j<m){
                curr = curr*(100-discounts[j])/100.0;
                j++;
            }
            result += curr;
        }
        return result;
    }
};