#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
#include<set>
using namespace std;

string make_str(char c,int l){
    string s = "";
    while(l--) s+=c;
    return s;
}
void generateWords(string ustr,map<char,int> fmap,int idx,string asf,int k){
    
    if(idx == ustr.length()){
        if(asf.length() == k)
            cout<<asf<<endl;
        return;
    }
    
    char ch = ustr[idx];
    for(int i = fmap[ch]; i >=0 ; i--){
        string temp = make_str(ch,i);
        generateWords(ustr,fmap,idx+1,asf+temp,k);
    }
}
void generateWords1(string ustr,map<char,int> fmap,int idx,string asf,int k){
    
    if(idx == ustr.length()){
        if(asf.length() == k)
            cout<<asf<<endl;
        return;
    }
    
    char ch = ustr[idx];
    if(fmap[ch] > 0){
        fmap[ch] -- ;
        generateWords1(ustr,fmap,idx,asf + ch,k);
        fmap[ch] ++ ;
    }
    generateWords1(ustr,fmap,idx+1,asf,k);
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
            unique[ch] = 1;
            s+=ch;
        }
        else
            unique[ch] ++;
    }
    
    // vector<char> spots(k,' ');
    // set<char> used;
    generateWords1(s, unique, 0, "", k);
}