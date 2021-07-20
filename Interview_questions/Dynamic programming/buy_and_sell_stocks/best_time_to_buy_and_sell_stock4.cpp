// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> dp_ik0(k+1,0);
        vector<int> dp_ik1(k+1,INT_MIN);
        for(int val:prices){
            for(int j = k;j>0;j--){
                dp_ik0[j] = max(dp_ik0[j],dp_ik1[j]+val);
                dp_ik1[j] = max(dp_ik1[j],dp_ik0[j-1]-val);
            }
        }
        // for(int j = k;j>=0;j--)
        //     cout<<dp_ik0[j]<<" ";
        // cout<<endl;
        return dp_ik0[k];
    }
};