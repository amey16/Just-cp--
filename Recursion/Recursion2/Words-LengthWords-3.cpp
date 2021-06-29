#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
using namespace std;

void generateWords(string ustr ,map<char,int> fmap,int idx, vector<char> spots,int ssf,int ss){
    
    if(idx == ustr.length()){
        if(ssf == ss){
            for(int i=0;i<spots.size();i++)
                if(spots[i]!=' ')   
                    cout<<spots[i];
            cout<<endl;
        }
        return;
    }
 
    char ch = ustr[idx];
    int lo = fmap[ch];
    for(int i = lo + 1;i < spots.size() ; i++){
        if(spots[i] == ' '){
            spots[i] = ch;
            fmap[ch] = i ;
            generateWords(ustr,fmap,idx+1,spots,ssf+1,ss);
            fmap[ch] = lo ;
            spots[i] = ' ';
        }
    }
    if(lo == -1)
        generateWords(ustr,fmap,idx+1,spots,ssf,ss);
}
int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    map<char,int> unique;
    string s = "";
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(unique.find(ch) == unique.end()){
            unique[ch] = -1;
            s += ch;
        }
    }
    
    vector<char> spots(k,' ');
    generateWords(str, unique, 0, spots, 0,k);
}