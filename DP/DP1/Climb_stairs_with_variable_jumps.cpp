#include <iostream>
#include <vector>
using namespace std;

int cs(int arr[], int n){
    
    vector<int> dp(n+1,0);
    dp[n]=1;
    for(int i = n-1 ; i>= 0; i--){
        for(int steps = 1 ;steps<=arr[i] ; steps++){
            if(i + steps>n)
                break;
            dp[i] += dp[i+steps];
        }
    }
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