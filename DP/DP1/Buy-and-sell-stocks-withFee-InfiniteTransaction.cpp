#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> stocks(n);
    for(int i=0;i<n;i++)
        cin>>stocks[i];
    int fee;
    cin>>fee;
    
    vector<int> bsp(n);
    vector<int> ssp(n);
    bsp[0] = -1*stocks[0];
    ssp[0] = 0;
    
    for(int i=1;i<n;i++){
        bsp[i] = max(ssp[i-1] - stocks[i],bsp[i-1]);
        ssp[i] = max(ssp[i-1],stocks[i] - fee + bsp[i-1]);
    }
    // for(int i=0;i<n;i++){
    //     cout<<bsp[i]<<" "<<ssp[i]<<endl;
    // }
    cout<<ssp[n-1]<<endl;
}