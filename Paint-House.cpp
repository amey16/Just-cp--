#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int mincostpaint(vector<vector<int>> arr,int n){
    
    vector<vector<int>> dp(3,vector<int>(n,0));
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[0][1];
    dp[2][0] = arr[0][2];
    
    for(int j = 1;j<n;j++){
        dp[0][j] = min(dp[1][j-1],dp[2][j-1]) + arr[j][0];
        dp[1][j] = min(dp[0][j-1],dp[2][j-1]) + arr[j][1];
        dp[2][j] = min(dp[0][j-1],dp[1][j-1]) + arr[j][2];
    }
    // for(int i=0;i<=2;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1]));

}
int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> arr;
    int r,b,g;
    for(int i=0;i<n;i++){
        vector<int> temp;
        cin>>r>>b>>g;
        temp.push_back(r);
        temp.push_back(b);
        temp.push_back(g);
        arr.push_back(temp);
    }
    cout<<mincostpaint(arr,n);
}