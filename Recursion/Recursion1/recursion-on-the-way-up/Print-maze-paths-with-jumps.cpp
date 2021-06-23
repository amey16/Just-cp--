#include<iostream>
#include <string>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    // write your code here
    if(sr == dr && sc == dc){
        cout<<psf<<endl;
        return;
    }        
    for(int h = 1 ; h <= dc-sc ; h++)
        printMazePaths(sr , sc + h , dr , dc , psf + "h" + to_string(h));
    for(int v = 1 ; v <= dr-sr ; v++)
        printMazePaths(sr + v , sc , dr , dc , psf + "v" + to_string(v));
    for(int d = 1 ; d <= dr-sr && d<= dc-sc ; d++)
        printMazePaths(sr + d,sc + d , dr , dc, psf + "d" + to_string(d));
}

int main() {
    int n ;
    int m ;cin>>n>>m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}