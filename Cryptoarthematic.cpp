# include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int getnum(string s1,map<char,int> charIntMap){
    string s = "";
    for(int i = 0;i<s1.length(); i++){
        s+= to_string(charIntMap[s1[i]]);
    }
    return stoi(s);
}
void solution(string unique,int idx,map<char,int> charIntMap,vector<bool> usedNumbers,string s1,string s2,string s3){
    
    if(idx == unique.length()){
        int num1 = getnum(s1,charIntMap);
        int num2 = getnum(s2,charIntMap);
        int num3 = getnum(s3,charIntMap);
        
        if(num1+num2 == num3){
            for(auto x=charIntMap.begin(); x!=charIntMap.end(); x++){
                cout<<x->first<<"-"<<x->second<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    char ch = unique[idx];
    for(int num = 0 ;num<=9;num++){
        if(usedNumbers[num] == false){
            charIntMap[ch] = num;
            usedNumbers[num] = true;
            solution(unique,idx+1,charIntMap,usedNumbers,s1,s2,s3);
            usedNumbers[num] = false;
            charIntMap[ch] = -1;
        }
    }
}
int main(){
    string s1,s2,s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;

    map<char, int> charIntMap;
    string unique = "";
    for(int i = 0; i < s1.length(); i++){
        if(charIntMap.find(s1[i]) == charIntMap.end()) {
            charIntMap[s1[i]] = -1;
            unique += s1[i];
        }
    }
    for(int i = 0; i < s2.length(); i++){
        if(charIntMap.find(s2[i]) == charIntMap.end()) {
            charIntMap[s2[i]] = -1;
            unique += s2[i];
        }
    }
    for(int i = 0; i < s3.length(); i++){
        if(charIntMap.find(s3[i]) == charIntMap.end()) {
            charIntMap[s3[i]] = -1;
            unique += s3[i];
        }
    }
    vector<bool> usedNumbers(10,false);
    solution(unique, 0, charIntMap, usedNumbers, s1, s2, s3);
  }