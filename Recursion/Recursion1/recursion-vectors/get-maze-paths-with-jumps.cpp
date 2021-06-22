#include<iostream>
#include<vector>
#include<string>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr == dr && sc == dc){
        return {""};
    }
    vector<string> path;
    for(int h = 1; h <= dc-sc ; h++){
        vector<string> hor= getMazePaths(sr,sc+h,dr,dc);
        for(int i=0;i<hor.size();i++){
            path.push_back("h"+to_string(h)+hor[i]);
        }
    }
    for(int v = 1; v <= dr-sr ; v++){
        vector<string> ver= getMazePaths(sr+v,sc,dr,dc);
        for(int i=0;i<ver.size();i++){
            path.push_back("v"+to_string(v)+ver[i]);
        }
    }
    for(int d = 1; d <= dc-sc && d <= dr-sr ; d++){
        vector<string> dig =getMazePaths(sr+d,sc+d,dr,dc);
        for(int i=0;i<dig.size();i++){
            path.push_back("d"+to_string(d)+dig[i]);
        }
    }    
    
    return path;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}