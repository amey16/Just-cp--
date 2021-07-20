// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i10 = 0;
        int dp_i11 = INT_MIN;
        for(int val: prices){
            dp_i10 = max(dp_i10,dp_i11+val);
            dp_i11 = max(dp_i11,-val);
        }
        return dp_i10;
    }
};