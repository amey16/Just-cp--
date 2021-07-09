#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> stocks(n);
    for(int i=0;i<n;i++)
        cin>>stocks[i];
        
    int crr_minima = INT_MAX;
    vector<int> op(n,0);
    int profit = 0,val = 0;
    for(int i=0;i<n;i++){
        if(crr_minima > stocks[i]){
            crr_minima = stocks[i];
        }
        profit = stocks[i] - crr_minima;
        if(i==0)
            continue;
        op[i] = op[i-1];
        if(op[i] < profit)
            op[i] = profit;
    }
    vector<int> opb(n,0);
    int crr_maxima = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(crr_maxima < stocks[i])
            crr_maxima = stocks[i];
        profit = crr_maxima - stocks[i];
        if(i==n-1)
            continue;
        opb[i] = opb[i+1];
        if(opb[i] < profit)
            opb[i] = profit;
    }
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = op[i] + opb[i];
        if(max < sum)
            max = sum;
    }
    
    cout<<max<<endl;
}