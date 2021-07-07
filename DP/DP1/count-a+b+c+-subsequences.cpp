#include<iostream>
#include<vector>
#include<string>
using namespace std;

int subsequence(string s){
    // cout<<s.length()<<endl;
    vector<vector<int>> dp(3,vector<int>(s.length()+1,0));
    
    for(int j=1;j<dp[0].size();j++){
        // cout<<j<<endl;
        int ch = s[j-1] - 'a';
        // cout<<ch<<" ";
        if(ch == 0){
            dp[0][j] = 2*dp[0][j-1] + 1;
            dp[1][j] = dp[1][j-1];
            dp[2][j] = dp[2][j-1];
        }
        else if(ch==1){
            dp[0][j] = dp[0][j-1];
            dp[1][j] = 2*dp[1][j-1] + dp[0][j-1];
            dp[2][j] = dp[2][j-1];
        }
        else{
            dp[0][j] = dp[0][j-1];
            dp[1][j] = dp[1][j-1];
            dp[2][j] = 2*dp[2][j-1] + dp[1][j-1];
        }
    }
    // for(int i=0;i<=2;i++){
    //     for(int j=0;j<dp[0].size();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // // cout<<endl;
    return dp[2][dp[0].size()-1];
}
int main(){
    string s;
    cin>>s;
    
    cout<<subsequence(s)<<endl;
}