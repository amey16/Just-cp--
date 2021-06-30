#include<iostream>
#include<vector>
#include<string>
using namespace std;

void display(vector<vector<int>> board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
bool isavailable(vector<vector<int>> board,int i,int j,int choice){
    for(int row = 0 ;row < board.size();row++){
        if(row == i)
            continue;
        if(board[row][j] == choice)
            return false;
    }
    for(int col = 0 ;col < board[0].size();col++){
        if(col == j)
            continue;
        if(board[i][col] == choice)
            return false;
    }
    int sm = i/3 * 3;
    int sj = j/3 * 3;
    for(int row = 0;row < 3;row++){
        for(int col = 0;col < 3;col++){
            if(board[row + sm][col + sj] == choice)
                return false;
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> board, int i, int j) {
    if(i == board.size()){
        display(board);
        return;
    }
    int nr = 0;
    int nc = 0;
    if(j == board.size()-1){
        nr = i+1;
        nc = 0;
    }
    else{
        nr = i;
        nc = j+1;
    }
    if(board[i][j] !=0)
        solveSudoku(board,nr,nc);
    else{
        for(int choice = 1; choice <= 9; choice++){
            if(isavailable(board,i,j,choice)){
                board[i][j] = choice;
                solveSudoku(board,nr,nc);
                board[i][j] = 0;
            }   
        }
    }
}
int main(){
    vector<vector<int>> board;
    for(int i = 0;i < 9;i++){
        vector<int> temp;
        int c;
        for(int j = 0;j < 9;j++){
            cin>>c;
            temp.push_back(c);
        }
        board.push_back(temp);
    }
    // cout<<endl;
    // display(board);
    // cout<<endl;
    solveSudoku(board,0,0);
}