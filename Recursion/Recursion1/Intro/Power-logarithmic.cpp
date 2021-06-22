#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    // write your code here
    if(n == 1)
        return x;
    int p = powerLogarithmic(x, n/2);
    int val = p * p;
    if(n % 2 == 1)
        val = val * x;
    return val;
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}