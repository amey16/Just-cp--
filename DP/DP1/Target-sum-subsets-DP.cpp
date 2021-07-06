#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int> arr,int sum){
    vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1,false));
    for(int i=0;i<dp.size();i++){
        dp[i][0] = true;
    }
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(dp[i-1][j] == true)
                dp[i][j] = true;
            if(j-arr[i-1] >=0 && dp[i-1][j-arr[i-1]] == true)
                dp[i][j] = true;
        }
    }
    // cout<<endl;
    // for(int i=0;i<dp.size();i++){
    //     for(int j=0;j<dp[0].size();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[dp.size()-1][dp[0].size()-1];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int c;
    for(int i=0;i<n;i++){
        cin>>c;
        arr.push_back(c);
    }
    int sum;
    cin>>sum;
    
    cout<<(solve(arr,sum)?"true":"false")<<endl;
    // if(solve(arr,sum))
    //     cout<<"true"<<endl;
    // else
    //     cout<<"false"<<endl;
}