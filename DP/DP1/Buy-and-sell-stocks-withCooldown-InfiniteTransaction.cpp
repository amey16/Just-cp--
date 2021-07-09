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
    
    vector<int> bsp(n);
    vector<int> ssp(n);
    vector<int> csp(n);
    bsp[0] = -1*stocks[0];
    ssp[0] = 0;
    csp[0] = 0;
    
    for(int i=1;i<n;i++){
        bsp[i] = max(csp[i-1] - stocks[i],bsp[i-1]);
        ssp[i] = max(ssp[i-1],stocks[i] + bsp[i-1]);
        csp[i] = ssp[i-1];
    }
    // for(int i=0;i<n;i++){
    //     cout<<bsp[i]<<" "<<ssp[i]<<endl;
    // }
    cout<<ssp[n-1]<<endl;
}