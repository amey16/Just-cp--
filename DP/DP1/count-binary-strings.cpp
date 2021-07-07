#include<iostream>
#include<vector>
using namespace std;


int count_binary(int n){
    
    vector<vector<int>> dp(2,vector<int>(n+1,0));
    dp[0][1] = 1;
    dp[1][1] = 1;
    for(int j = 2;j<=n;j++){
        dp[0][j] = dp[1][j-1];
        dp[1][j] = dp[0][j-1] + dp[1][j-1];
    }
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[0][n] + dp[1][n];
}
int main(){
    int n;
    cin>>n;
    
    cout<<count_binary(n)<<endl;
}