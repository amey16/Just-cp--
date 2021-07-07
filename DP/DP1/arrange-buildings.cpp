#include<iostream>
#include<vector>
using namespace std;


long long build_buildings(int n){
    
    vector<vector<long long>> dp(2,vector<long long>(n+1,0));
    dp[0][1] = 1;
    dp[1][1] = 1;
    for(int j = 2;j<=n;j++){
        dp[0][j] = dp[1][j-1];
        dp[1][j] = dp[0][j-1] + dp[1][j-1];
    }
    long long ans = dp[0][n] + dp[1][n] ; 
    return ans*ans;
}
int main(){
    int n;
    cin>>n;
    
    cout<<build_buildings(n)<<endl;
}