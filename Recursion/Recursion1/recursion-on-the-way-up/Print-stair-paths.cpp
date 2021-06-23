#include <iostream>
#include <string>
using namespace std;

void printStairPaths(int n, string psf){
    // write your code here
    if(n<0){
        return;
    }
    if(n == 0){
        cout<<psf<<endl;
        return;
    }
    for(int steps=1;steps<=3;steps++)
        printStairPaths(n-steps,psf+to_string(steps));
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}