#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
using namespace std;

void combination(int i,string ustr,int ssf, int ts, string asf ){
    
    if(i == ustr.length()){
        if(ssf == ts)
            cout<<asf<<endl;
        return;
    }
    
    char ch = ustr[i];
    combination(i+1,ustr,ssf+1,ts,asf + ch);
    combination(i+1,ustr,ssf,ts,asf + "");
}
int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    map<char,int> unique;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(unique.find(ch) == unique.end())
            unique[ch] = 1;
        else
            unique[ch] ++;
    }
    string s = "";
    for(auto& x:unique)
        s +=x.first;
    // cout<<s<<endl;
    
    combination(0,s,0,k,"");
    // generateWords(0, str, spots, lastOccurence);
}