#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> stocks(n);
    for(int i=0;i<n;i++)
        cin>>stocks[i];
        
    int crr_minima = INT_MAX;
    int profit = 0,op = 0;
    for(int i=0;i<n;i++){
        if(crr_minima > stocks[i]){
            crr_minima = stocks[i];
        }
        profit = stocks[i] - crr_minima;
        if(op<profit){
            op = profit;
        }
    }
    cout<<op<<endl;
}