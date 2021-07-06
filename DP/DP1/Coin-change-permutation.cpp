#include<vector>
#include<iostream>
using namespace std;


int perm(vector<int> arr,int n,int sum){
    
    vector<int> dp(sum+1,0);
    dp[0] = 1;
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            int coin = arr[j];
            if(i-coin >=0){
                dp[i] = dp[i] + dp[i-coin];
            }
        }
    }
    return dp[sum];
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
    cout<<perm(arr,n,sum);
}