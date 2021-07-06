#include<iostream>
#include<vector>
using namespace std;

int minele(int a,int b){
    return a<=b?a:b;
}
int mincost(vector<vector<int>> arr,int n,int m){
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[n-1][m-1] = arr[n-1][m-1];
        
    for(int i = n-2;i>=0;i--){
        dp[i][m-1] = dp[i+1][m-1] + arr[i][m-1];
    }
    for(int j = m-2;j>=0;j--){
        dp[n-1][j] = dp[n-1][j+1] + arr[n-1][j];
    }
    
    for(int i = n-2; i>=0 ; i--){
        for(int j = m-2; j>=0 ; j--){
            dp[i][j] = minele(dp[i+1][j],dp[i][j+1]) + arr[i][j];
        }
    }
    return dp[0][0];
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
    cout<<mincost(arr,n,m);
}