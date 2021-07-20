// https://www.lintcode.com/problem/514/

class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code here
        vector<vector<int>> dp(2,vector<int>(n,0));
        if(n==0 || n==1)
            return k;
        dp[0][0] = k;
        dp[1][0] = k;
        dp[0][1] = k;
        dp[1][1] = k * (k-1);
        int total = dp[0][1] + dp[1][1];
        for(int i = 2;i<n;i++){
            dp[0][i] = dp[1][i-1];
            dp[1][i] = total * (k-1);
            total = dp[0][i] + dp[1][i];
        }
        // for(int i=0;i<dp.size();i++){
        //     for(int j=0;j<dp[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return total;
    }
};