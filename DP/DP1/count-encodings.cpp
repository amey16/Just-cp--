#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


int count_encodings(string s){
    
    vector<int> dp(s.length(),0);
    char ch = s[0];
    dp[0] = 1;
    
    for(int i=1;i<dp.size();i++){
        int ch0 = s[i-1]-'0';
        int ch1 = s[i]-'0';
        int num = ch0*10 + ch1;
        // cout<<num<<endl;
        if(ch1!=0){
            dp[i] += dp[i-1];
        }
        
        if(num == 0){
            dp[i] = 0;
        }
        else if(num == 10 || num == 20){
            dp[i] += dp[i-2];
        }
        else if(num>10 && num<=26 && num != 20){
            // dp[i] += dp[i-1];
            if(i==1)
                dp[i] += 1;
            else
                dp[i] += dp[i-2];
        }
        
    }
    // for(int i=0;i<s.length();i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    
    return dp[dp.size()-1];
}
int main(){
    string s;
    cin>>s;
    
    cout<<count_encodings(s)<<endl;
}