#include<iostream>
#include<vector>
#include<string>
using namespace std;

void coinChange(vector<int> coins, int amtsf, int tamt, string asf, vector<bool> used){
    if(amtsf>tamt)
        return;
    if(amtsf == tamt){
        cout<<asf<<"."<<endl;
        return;
    }
    for(int i = 0 ;i < coins.size();i++){
        int coin = coins[i];
        if(used[i] == false){
            used[i] = true;
            coinChange(coins,amtsf + coin,tamt,asf+to_string(coin)+"-",used);
            used[i] = false;
        }
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
    vector<bool> used(n,false);
    coinChange(a,0,sum,"",used);
}