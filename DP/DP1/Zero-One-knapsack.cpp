#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxval(vector<int> values,vector<int> weights,int n,int twsum){
    
    vector<vector<int>> dp(n+1,vector<int>(twsum+1,0));
    
    for(int i=1;i<n+1;i++){
        int weight = weights[i-1];
        int value = values[i-1];
        for(int j=1;j<=twsum;j++){
            if(j-weight>=0)
                dp[i][j] = max(dp[i-1][j],value+dp[i-1][j-weight]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=twsum;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    return dp[n][twsum];
}
int main(){
    int n,c;
    cin>>n;
    vector<int> values;
    vector<int> weights;
    
    for(int i=0;i<n;i++){
        cin>>c;
        values.push_back(c);
    }
    for(int i=0;i<n;i++){
        cin>>c;
        weights.push_back(c);
    }
    
    int twsum;
    cin>>twsum;
    
    cout<<maxval(values,weights,n,twsum)<<endl;
}