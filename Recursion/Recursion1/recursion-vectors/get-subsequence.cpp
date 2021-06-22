#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> gss(string s){
    // write your code here
    if(s.size() == 0){
        return {""};
    }
    char ch = s[0];
    string sub = s.substr(1,s.length() - 1);
    vector<string> set = gss(sub);
    vector<string> temp = {};
    for(string s1:set){
        temp.push_back(""+s1);
    }
    for(string s1:set){
        temp.push_back(ch+s1);
    }
    return temp;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}