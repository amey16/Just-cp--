#include<iostream>
#include<vector>
#include<string>
using namespace std;

void coinChange(int i, vector<int> coins, int amtsf, int tamt, string asf){
    if(i == coins.size()){
        if(amtsf == tamt)
            cout<<asf<<"."<<endl;
        return;
    }
    int coin = coins[i];
    coinChange(i+1,coins,amtsf + coin , tamt , asf + to_string(coin) + "-");
    coinChange(i+1,coins,amtsf , tamt , asf);
    
}
int main(){
    int n;
    vector<int> a;
    int sum,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        a.push_back(c);
    }
    cin>>sum;
    coinChange(0,a,0,sum,"");
}