#include <iostream>
#include<vector>
using namespace std;

int fib(int n,vector<int>& qb){
    if(n==0 || n==1)
        return n;
    if(qb[n]!=0)
        return qb[n];
    
    int fib1 = fib(n-1,qb);
    int fib2 = fib(n-2,qb);
    int fibn = fib1+fib2;
    
    qb[n] = fibn;
    return fibn;
}

int main(){
    int n;
    cin>>n;
    vector<int> array(n+1,0);
    cout<<fib(n,array)<<endl;
    return 0;
}