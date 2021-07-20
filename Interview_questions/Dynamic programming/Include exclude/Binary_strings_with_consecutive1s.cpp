// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

#include <iostream>
using namespace std;
 
int countStrings(int n){
    int a[n], b[n];
    a[0] = b[0] = 1;
    for(int i=1;i< n;i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}
// O(1) space
int countStrings2(int n){
    int a=1,b=1;
    for(int i=1;i<n;i++){
        int temp = a;
        a = a+b;
        b = temp;
    }
    return a+b;
}
 
int main(){
    cout<<countStrings2(3)<<endl;
    return 0;
}