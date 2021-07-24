#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1;
    unordered_map<int,int> m;
    int c;
    for(int i=0;i<n1;i++){
        cin>>c;
        if(m.find(c) == m.end())
            m[c] = 1;
        else 
            m[c]++;
    }
    cin>>n2;
    vector<int> b(n2);
    for(int i=0;i<n2;i++){
        cin>>b[i];
        if(m.find(b[i]) != m.end()){
            cout<<b[i]<<endl;
            m.erase(b[i]);
        }
    }
}