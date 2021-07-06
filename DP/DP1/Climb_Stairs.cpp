#include <iostream>
#include <vector>
using namespace std;

int cs(int n){
    // write your code here
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<n+1;i++){
        if(i==1)
            dp[i] = dp[i-1];
        else if(i==2)
            dp[i] = dp[i-1] + dp[i-2] ;
        else
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];

}

int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}