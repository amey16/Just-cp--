#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<string> letters = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string> kpc(string num){
    if(num.length()==0)
        return {""};
    int idx = num[0]-48;
    string s = num.substr(1,num.length()-1);
    vector<string> ans = kpc(s);
    
    vector<string> temp;
    string atnum = letters[idx]; 
    for(int i=0; i < atnum.length(); i++){
        char t = atnum[i];
        for(string res : ans){
            temp.push_back(t + res);
        }
    }
    return temp;
}

int main(){
    string num;
    cin>>num;
    vector<string> ans = kpc(num);
    cout<<"[";
    for (int i = 0; i < ans.size();i++){
        cout<<ans[i];
        if(i != ans.size()-1)
            cout<<", ";
    }
    cout<<"]";
}