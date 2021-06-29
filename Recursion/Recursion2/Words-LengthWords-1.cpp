#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
using namespace std;

void generateWords(int cc,string ustr,int ssf ,int ts,vector<char> spots){
    if(cc == ustr.length()){
        if(ssf == ts){
            for(int i=0;i<spots.size();i++){
                if(spots[i]!=' ')
                    cout<<spots[i];
            }
            cout<<endl;
        }
        return;
    }
    
    char ch = ustr[cc];
    for(int i = 0; i<ustr.length();i++){
        if(spots[i] == ' '){
            spots[i] = ch;
            generateWords(cc+1,ustr,ssf+1,ts,spots);
            spots[i] = ' ';
        }
    }
    generateWords(cc+1,ustr,ssf,ts,spots);
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
            s += ch;
        }
        else
            unique[ch] ++;
    }
    // string s = "";
    // for(auto& x:unique)
    //     s +=x.first;
    
    vector<char> spots(k,' ');
    generateWords(0, s, 0, k, spots);
}