#include<iostream>
#include<vector>
using namespace std;

void queensCombinations(int qpsf, int tq, int row, int col, string asf){
    // write your code here
    if(row == tq){
        if(qpsf == tq)
            cout<<asf<<endl;
        return;
    }
    string yasf="",nasf="";
    int r=0 ,c=0;
    if(col == tq -1){
        r = row + 1;
        c = 0;
        yasf = asf + "q\n";
        nasf = asf + "-\n";
    }
    else{
        r = row;
        c = col+1;
        yasf = asf +"q";
        nasf = asf +"-";
    }
    queensCombinations(qpsf+1,tq,r,c,yasf);
    queensCombinations(qpsf+0,tq,r,c,nasf);
}

int main(){
    int n;
    cin>>n;
    queensCombinations(0, n, 0, 0, "");
}
