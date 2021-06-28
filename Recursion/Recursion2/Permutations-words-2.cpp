#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
using namespace std;

void generateWords(int cc, string str, vector<char> spots, map<char,int> lastOccurence) {
    
    if(cc == str.length()){
        for(int i=0;i<spots.size();i++){
            cout<<spots[i];
        }
        cout<<endl;
        return;
    }
    char ch = str[cc];
    int l = lastOccurence[ch];
    
    for(int i=l+1;i<spots.size();i++){
        if(spots[i] == ' '){
            spots[i] = ch;
            lastOccurence[ch] = i;
            generateWords(cc+1,str,spots,lastOccurence);
            lastOccurence[ch] = -1;
            spots[i] = ' ';
        }
    }
}

int main(){
    string str;
    cin>>str;

    vector<char> spots(str.length(),' ');
    map<char,int> lastOccurence;
    for(int i=0 ;i < str.length();i++){
        char ch = str[i];
        if(lastOccurence.find(ch) == lastOccurence.end())
            lastOccurence[ch] = -1;
    }
    generateWords(0, str, spots, lastOccurence);
}