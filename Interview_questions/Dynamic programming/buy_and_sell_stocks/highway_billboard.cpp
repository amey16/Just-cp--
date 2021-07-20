// https://www.geeksforgeeks.org/highway-billboard-problem/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxRevenue(int m,vector<int> x,vector<int> revenue,int n,int t){
    vector<int> dp(m+1,0);
    int index = 0;
    for (int i = 1; i <= m; i++){
        if (index < n){
            if (x[index] != i)
                dp[i] = dp[i-1];
            else{
                if (i <= t)
                    dp[i] = max(dp[i-1], revenue[index]);
                else
                    dp[i] = max(dp[i-t-1]+revenue[index], dp[i-1]);
                index++;
            }
        }
        else
            dp[i] = dp[i-1];
    }
    return dp[m];
}
int main(){
    int m;
    cin>>m;

    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> revenue(n);

    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
        cin>>revenue[i];
    
    int t;
    cin>>t;

    cout<<maxRevenue(m,x,revenue,n,t)<<endl;
}