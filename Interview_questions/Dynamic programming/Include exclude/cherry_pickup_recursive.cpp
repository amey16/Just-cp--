// https://leetcode.com/problems/cherry-pickup/

class Solution {
public:
    int sol(vector<vector<vector<int>>>& dp,vector<vector<int>>& grid,int x1,int y1,int y2){
        int x2 = x1+y1-y2;
        int n = grid.size();
        if(x1 >= n || y1 >= n || x2 >= n || y2 >=n || 
           grid[x1][y1] == -1 || grid[x2][y2] == -1){
            return -999999;
        }
        else if(dp[x1][y1][y2] != INT_MIN)  
            return dp[x1][y1][y2];
        else if(x1 == n-1 && y1 == n-1)
            return grid[x1][y1];
        int ans = 0;
        if(x1==x2 && y1==y2)
            ans = grid[x1][y1];
        else
            ans = grid[x1][y1] + grid[x2][y2];
        int s1 = sol(dp,grid,x1,y1+1,y2+1);
        int s2 = sol(dp,grid,x1+1,y1,y2+1);
        int s3 = sol(dp,grid,x1,y1+1,y2);
        int s4 = sol(dp,grid,x1+1,y1,y2);
        ans += max(max(s1,s2),max(s3,s4));
        dp[x1][y1][y2] = ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         for(int k=0;k<n;k++){
        //             cout<<dp[i][j][k]<<" ";
        //         }
        //         cout<<"     ";
        //     }
        //     cout<<endl;
        // }
        int ans = sol(dp,grid,0,0,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         for(int k=0;k<n;k++){
        //             cout<<dp[i][j][k]<<" ";
        //         }
        //         cout<<"     ";
        //     }
        //     cout<<endl;
        // }
        return max(0,ans);
    }
};


