#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
#include<set>
using namespace std;

void generateWords(int cs,int ts,string ustr,set<char> used,string asf){
    if(cs == ts){
        cout<<asf<<endl;
        return;
    }
    for(int i=0;i<ustr.length();i++){
        char ch = ustr[i];
        if(used.find(ch) == used.end()){
            used.insert(ch);
            generateWords(cs+1,ts,ustr,used,asf+ch);
            used.erase(ch);
        }
    }
}
int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    string s ="";
    map<char,int> unique;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(unique.find(ch) == unique.end()){
            unique[ch] = 1;
            s+=ch;
        }
        else
            unique[ch] ++;
    }
    // string s = "";
    // for(auto& x:unique)
        // s +=x.first;
    
    vector<char> spots(k,' ');
    set<char> used;
    generateWords(0, k, s, used, "");
}