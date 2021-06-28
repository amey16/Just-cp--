#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include<map>
using namespace std;

void generateWords(int cs, int ts, map<char, int> fmap, string asf){
    if(cs > ts){
        cout<<asf<<endl;
        return;
    }
    for(auto& x : fmap){
        char ch = x.first;
        if(fmap[ch]!=0){
            fmap[ch] --;
            generateWords(cs+1,ts,fmap,asf+ch);
            fmap[ch] ++;
        }
    }
}

int main(){
    string str;
    cin>>str;

    map<char, int> fmap;
    for(int i=0 ;i < str.length();i++){
        char ch = str[i];
        if(fmap.find(ch) == fmap.end())
            fmap[ch] = 1;
        else
            fmap[ch] ++;
    }
    // vector<char> a;
    // for(auto p=fmap.begin(); p!=fmap.end() ;p++)
    //     a.push_back(p->first);
    
    // for(int i = 0 ;i<a.size();i++)
        // cout<<a[i]<<" ";
    
    generateWords(1, str.length(), fmap, "");
}