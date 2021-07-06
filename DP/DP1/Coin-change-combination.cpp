#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> coins,int n,int sum){
    vector<int> dp(sum+1,0);
    dp[0] = 1;
    
    for(int i=0;i<n;i++){
        int coin = coins[i];
        for(int j =1 ;j<=sum;j++){
            if(j-coin >= 0 && dp[j-coin] != 0){
                dp[j] = dp[j-coin] + dp[j];
            }
        }
    }
    return dp[sum];
}
int main(){
    int n;
    cin>>n;
    vector<int> coins;
    int c;
    for(int i=0;i<n;i++){
        cin>>c;
        coins.push_back(c);
    }
    int sum;
    cin>>sum;
    
    cout<<solve(coins,n,sum)<<endl;
}