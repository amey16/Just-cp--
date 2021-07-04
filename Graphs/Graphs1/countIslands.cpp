#include<iostream>
#include<vector>
using namespace std;

void getnoIslands(vector<vector<int>> map,int i,int j,vector<vector<bool>>& visted){
    
    
    if(i<0 || j<0 || i>=map.size() || j>=map[0].size() || map[i][j] == 1 || visted[i][j] == true){
        return;
    }
    visted[i][j] = true;
    getnoIslands(map,i-1,j,visted);
    getnoIslands(map,i,j+1,visted);
    getnoIslands(map,i+1,j,visted);
    getnoIslands(map,i,j-1,visted);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> map;
    for(int i=0;i<n;i++){
        vector<int> temp;
        int c;
        for(int j=0;j<n;j++){
            cin>>c;
            temp.push_back(c);
        }
        map.push_back(temp);
    }
    vector<vector<bool>> visted(n,vector<bool>(m,false));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 0 && visted[i][j] == false)
                count++;
                getnoIslands(map,i,j,visted);
        }
    }
    cout<<count<<endl;
}