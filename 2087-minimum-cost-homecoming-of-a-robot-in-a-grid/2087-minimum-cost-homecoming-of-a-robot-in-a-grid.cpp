class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int result = 0;
        int i = startPos[0];
        int j = startPos[1];
        int ti = homePos[0];
        int tj = homePos[1];
        for(int k=i+1;k<=ti;k++) result += rowCosts[k];
        for(int k=j+1;k<=tj;k++) result += colCosts[k];
        for(int k=i-1;k>=ti;k--) result += rowCosts[k];
        for(int k=j-1;k>=tj;k--) result += colCosts[k];
        return result;
    }
};