#include<iostream>
#include<vector>
#include<string>
using namespace std;

void queensPermutations(int qpsf, int tq, int row, int col, string asf, vector<bool> queens) {
    if(row == tq){
        if(qpsf == tq){
            cout<<asf<<endl;
            cout<<endl;
        }
        return;
    }
        
    int nr = 0;
    int nc = 0;
    string a = " ";
    if(col == tq-1){
        nr = row+1;
        nc = 0;
        a = "";
    }
    else{
        nr = row;
        nc = col+1;
        a = "	"; 
    }
        
    for(int j =0 ;j < queens.size() ; j++){
        if(queens[j] == false){
            queens[j] = true;
            queensPermutations(qpsf+1,tq,nr,nc,asf + "q" + to_string(j+1) + a,queens);
            queens[j] = false;
        }
    }
    queensPermutations(qpsf + 0 ,tq,nr,nc,asf + "-" + a,queens);
}

int main(){
    int n;
    cin >> n;
    vector<bool> queens(n,false);
    queensPermutations(0,n,0,0,"",queens);
}