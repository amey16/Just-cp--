#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxele(int a,int b){
    return a>=b?a:b;
}
int solve(vector<vector<int>> arr,int n,int m){
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        dp[i][m-1] = arr[i][m-1];
    }
    for(int j=m-2;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(i==0)
                dp[i][j] = maxele(dp[i+1][j+1],dp[i][j+1]) + arr[i][j];
            else if(i==n-1)
                dp[i][j] = maxele(dp[i-1][j+1],dp[i][j+1]) + arr[i][j];
            else
                dp[i][j] = maxele(dp[i+1][j+1],maxele(dp[i][j+1],dp[i-1][j+1])) + arr[i][j];
        }
    }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        max = maxele(max,dp[i][0]);
    }
    return max;
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        vector<int> temp;
        int c;
        for(int j=0;j<m;j++){
            cin>>c;
            temp.push_back(c);
        }
        arr.push_back(temp);
    }
    cout<<solve(arr,n,m)<<endl;
}