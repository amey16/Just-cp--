#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> stocks(n);
    for(int i=0;i<n;i++){
        cin>>stocks[i];
    }
    
    int profit = 0;
    int bi = 0;
    int si = 0;
    
    for(int i=1;i<n;i++){
        if(stocks[i] >= stocks[i-1])
            si++;
        else{
            profit += (stocks[si] - stocks[bi]);
            bi = i;
            si = i;
        }
    }
    profit+=(stocks[si] - stocks[bi]);
    
    cout<<profit<<endl;
}