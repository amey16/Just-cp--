#include<iostream>
#include<vector>
#include<string>
using namespace std;

void queensCombinations(int qpsf, int tq, vector<vector<bool>> chess, int lcno){
    // write your code here
    if(qpsf == tq){
        for(int row = 0; row<chess.size();row++){
            for(int col = 0 ; col < chess[0].size() ; col++){
                if(chess[row][col] == true)
                    cout<<"q\t";
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
        chess[row][col] = true;
        queensCombinations(qpsf+1,tq,chess,i);
        chess[row][col] = false;
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<vector<bool>> chess(n,vector<bool>(n,false));
    queensCombinations(0, n, chess, -1);
}