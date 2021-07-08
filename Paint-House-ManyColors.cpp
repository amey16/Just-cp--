#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int mincostpaint(vector<vector<int>> arr,int n,int p){
    
    vector<vector<int>> dp(p,vector<int>(n,0));
    for(int i=0;i<p;i++)
        dp[i][0] = arr[0][i];
    
    for(int j = 1;j<n;j++){
        for(int i=0;i<p;i++){
            // cout<<minreturnarr(dp[j-1],i)<<" ";
            int minele = INT_MAX;
            for(int k=0;k<dp.size();k++){
                if(k != i){
                    minele = min(minele,dp[k][j-1]);
                }
            }
            dp[i][j] = minele + arr[j][i];
        }
        // cout<<endl;
    }
    // cout<<endl;
    // for(int i=0;i<p;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int minele = INT_MAX;
    for(int k=0;k<dp.size();k++){
        minele = min(minele,dp[k][n-1]);
    }
    return minele;

}
int main(){
    int n,p;
    cin>>n>>p;
    
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int c;
        vector<int> temp;
        for(int j=0;j<p;j++){
            cin>>c;
            temp.push_back(c);
        }
        arr.push_back(temp);
    }
    cout<<mincostpaint(arr,n,p);
}