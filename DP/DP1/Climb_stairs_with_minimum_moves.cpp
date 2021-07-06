#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minele(int a,int b){
    return a<=b?a:b;
}
int cs(int arr[], int n){
    
    vector<int> dp(n+1,-1);
    dp[n]=0;
    for(int i = n-1 ; i>= 0; i--){
        if(arr[i]>0){
            int min = INT_MAX;
            for(int steps = 1;steps<=arr[i];steps++){
                if(dp[i+steps] != -1){
                    min = minele(min,dp[i+steps]);
                }
            }
            if(min!=INT_MAX)
                dp[i] = min + 1 ;
        }
    }
    // for(int i=0;i<n+1;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    return dp[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}