#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxadj(vector<int> arr,int n){
    vector<vector<int>> dp(2,vector<int>(n,0));
    
    dp[0][0] = arr[0];
    dp[1][0] = 0;
    for(int j= 1;j<n;j++){
        dp[0][j] = dp[1][j-1] + arr[j];
        dp[1][j] = max(dp[0][j-1],dp[1][j-1]);
    }
    return max(dp[0][n-1],dp[1][n-1]);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<maxadj(arr,n)<<endl;
}