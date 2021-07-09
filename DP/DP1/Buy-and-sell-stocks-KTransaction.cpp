#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> stocks(n);
    for(int i=0;i<n;i++)
        cin>>stocks[i];
    int k;
    cin>>k;
    
    vector<vector<int>> dp(k+1,vector<int> (n,0));
    for(int i=1;i<=k;i++){
        int max = INT_MIN;
        for(int j=1;j<n;j++){
            if(dp[i-1][j-1] - stocks[j-1] > max)
                max = dp[i-1][j-1] - stocks[j-1];
            if(max + stocks[j] > dp[i][j-1])
                dp[i][j] = max+stocks[j];
            else
                dp[i][j] = dp[i][j-1];
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<dp[k][n-1]<<endl;
}