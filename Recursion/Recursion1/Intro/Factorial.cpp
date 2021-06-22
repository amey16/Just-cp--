#include<iostream>
using namespace std;

int factorial(int n){
    // write your code here
    if(n == 0)
        return 1;
    int f = factorial(n-1);
    int val = f*n;
    return val;
}


int main(){
    int n; cin>>n;
    cout<<factorial(n);
}