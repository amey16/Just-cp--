#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxval(vector<int> values,vector<int> weights,int n,int twsum){
    
    vector<int> dp(twsum+1,0);
    
    for(int i=1;i<=twsum;i++){
        for(int j=0;j<n;j++){
            int weight = weights[j];
            int value = values[j];
            if(i-weight >= 0)
                dp[i] = max(dp[i],dp[i-weight] + value);
        }
    }
    
    return dp[twsum];
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