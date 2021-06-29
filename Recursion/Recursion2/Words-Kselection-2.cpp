#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
using namespace std;

void combination(string ustr,int cs,int ts,int lc, string asf ){
    
    if(cs==ts){
        cout<<asf<<endl;
        return;
    }
    
    for(int i = lc+1;i<ustr.length();i++){
        char ch = ustr[i];
        combination(ustr,cs+1,ts,i,asf + ch);
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
            s+= ch;
        }
        else
            unique[ch] ++;
    }
    // string s = "";
    // for(auto& x:unique)
    //     s +=x.first;
    // cout<<s<<endl;
    
    combination(s,0,k,-1,"");
    // generateWords(0, str, spots, lastOccurence);
}