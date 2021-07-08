#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int countfence(int n,int k){
    vector<vector<int>> dp(3,vector<int>(n,0));
    dp[0][1] = k;
    dp[1][1] = k * (k-1);
    dp[2][1] = dp[0][1] + dp[1][1];
    
    for(int j=2;j<n;j++){
        dp[0][j] = dp[1][j-1];
        dp[1][j] = dp[2][j-1]*(k-1);
        dp[2][j] = dp[0][j] + dp[1][j];
    }
    return dp[2][n-1];
}
int main(){
    int n,k;
    cin>>n;
    cin>>k;
    
    cout<<countfence(n,k)<<endl;
}