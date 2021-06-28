#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool IsQueenSafe(vector<vector<int>> chess, int row, int col) {
    // write your code here
    for(int r = row;r>=0;r--){
        if(chess[r][col] != 0)
            return false;
    } //west
    for(int c = col;c>=0;c--){
        if(chess[row][c] != 0)
            return false;
    } // north
    for(int r = row , c = col ; r>=0 && c>=0 ; r--,c--){
        if(chess[r][c] != 0)
            return false;
    } // north-west
    for(int r = row , c = col ; r>=0 && c<chess[0].size() ; r--,c++){
        if(chess[r][c] != 0)
            return false;
    } // north-east
    for(int r = row;r<chess.size();r++){ 
        if(chess[r][col] != 0)
            return false;
    } // south
    for(int c = col;c<chess[0].size();c++){
        if(chess[row][c] != 0)
            return false;
    } //east
    for(int r = row , c = col ; r<chess.size() && c>=0 ; r++,c--){
        if(chess[r][c] != 0)
            return false;
    }
    for(int r = row , c = col ; r<chess.size() && c<chess[0].size() ; r++,c++){
        if(chess[r][c] != 0)
            return false;
    }
    return true;
}

void nqueens(int qpsf, int tq, vector<vector<int>> chess) {
    if(qpsf == tq){
        for(int row = 0; row<chess.size();row++){
            for(int col = 0 ; col < chess[0].size() ; col++){
                if(chess[row][col] != 0)
                    cout<<"q"<<to_string(chess[row][col])<<"\t";
                else
                    cout<<"-\t";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for (int i = 0; i < chess.size() * chess[0].size(); i++) {
        int row = i / chess.size();
        int col = i % chess.size();

        if (chess[row][col] ==0 && IsQueenSafe(chess, row, col)) {
            chess[row][col] = qpsf + 1;
            nqueens(qpsf + 1, tq, chess);
            chess[row][col] = 0;
        }
    }
    
    
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> chess(n,vector<int>(n,0));
    nqueens(0, n, chess);
}