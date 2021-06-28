#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool IsKnightSafe(vector<vector<bool>> chess, int i, int j) {
    if(i-1 >= 0 && j-2 >= 0 && chess[i-1][j-2] == true){
            return false;
    }
    if(i-1 >= 0 && j+2 <chess[0].size() && chess[i-1][j+2] == true){
            return false;
    }
    if(i-2>=0 && j-1>= 0 && chess[i-2][j-1] == true){
            return false;
    }
    if(i-2 >= 0 && j+1 <chess[0].size() && chess[i-2][j+1] == true){
            return false;
    }
    return true;
    
}

void nknights(int kpsf, int tk, vector<vector<bool>> chess, int lcno){
    // write your code here
    if(kpsf == tk){
        for(int row = 0; row<chess.size();row++){
            for(int col = 0 ; col < chess[0].size() ; col++){
                if(chess[row][col] == true)
                    cout<<"k\t";
                else
                    cout<<"-\t";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int i = lcno+1;i < chess.size()*chess[0].size();i++){
        int row = i / chess.size();
        int col = i % chess.size();
        
        if(IsKnightSafe(chess, row, col)){
            chess[row][col] = true;
            nknights(kpsf+1,tk,chess,row * chess.size() + col);
            chess[row][col] = false;
        }
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<vector<bool>> chess(n,vector<bool>(n,false));
    nknights(0, n, chess, -1);
}