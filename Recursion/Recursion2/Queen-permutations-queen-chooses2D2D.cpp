#include<iostream>
#include<vector>
#include<string>
using namespace std;

void queensPermutations(int qpsf, int tq, vector<vector<int>> chess){
    // write your code here
    if(qpsf == tq){
        for(int i=0;i<chess.size();i++){
            for(int j=0;j<chess[0].size();j++){
                if(chess[i][j] == 0)
                    cout << "-	";
                else
                    cout<<"q"+to_string(chess[i][j])+"	";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int i=0;i<chess.size();i++){
            for(int j=0;j<chess[0].size();j++){
                if(chess[i][j] == 0){
                    chess[i][j] = qpsf+1;
                    queensPermutations(qpsf+1,tq,chess);
                    chess[i][j] = 0;
                }
            }
        }
    
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> chess(n,vector<int>(n,0));
    queensPermutations(0, n, chess);
}