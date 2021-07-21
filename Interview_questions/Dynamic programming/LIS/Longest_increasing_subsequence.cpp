// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        int ans = 0;
        for(int val:nums){
            int i=0;
            int j=ans;
            while(i<j){
                int mid = i + (j-i)/2;
                if(dp[mid] < val)
                    i = mid+1;
                else
                    j= mid;
            }
            dp[i] = val;
            if(i==ans)
                ans++;
        }
        // for(int i=0;i<n;i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        return ans;
    }
};