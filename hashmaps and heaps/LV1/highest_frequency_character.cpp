#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char,int> m;
    for(int i=0;i<s.length();i++){
        if(m.find(s[i]) == m.end())
            m[s[i]] = 1;
        else
            m[s[i]]++;
    }
    char mfc = s[0];
    for(auto i:m){
        if(m[mfc] < i.second)
            mfc = i.first;
    }
    cout<<mfc<<endl;
}