#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
#include<set>
using namespace std;

void generateWords(string ustr,map<char,int> fmap,int sl,int tl,string asf){
    
    if(sl == tl){
        cout<<asf<<endl;
        return;
    }
    
    for(int i = 0;i < ustr.length();i++){
        char ch = ustr[i];
        if(fmap[ch]!=0){
            fmap[ch]--;
            generateWords(ustr,fmap,sl+1,tl,asf+ch);
            fmap[ch]++;
        }
    }
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

    generateWords(s, unique, 0, k,"");
}