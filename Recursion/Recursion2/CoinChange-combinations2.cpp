#include<iostream>
#include<vector>
#include<string>
using namespace std;

void coinChange(int li, vector<int> coins, int amtsf, int tamt, string asf){
    if(amtsf > tamt)
        return;
    if(amtsf == tamt){
        cout<<asf<<"."<<endl;
        return;
    }
    for(int i=li;i<coins.size();i++){
        int coin = coins[i];
        coinChange(i,coins,amtsf + coin , tamt , asf + to_string(coin) + "-");
    }
    
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