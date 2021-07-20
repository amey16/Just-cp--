https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i10 = 0,dp_i20 = 0;
        int dp_i11 = INT_MIN,dp_i21 = INT_MIN;
        for(int val: prices){
            int tempdp_i10 = dp_i10;
            dp_i20 = max(dp_i20,dp_i21+val);
            dp_i21 = max(dp_i21,dp_i10-val);
            dp_i10 = max(dp_i10,dp_i11+val);
            dp_i11 = max(dp_i11,-val);
        }
        return dp_i20;
    }
};
