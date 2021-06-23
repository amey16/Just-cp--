#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here
    if(ques.length()==0){
        cout<<asf<<endl;
        return;
    }
    int idx = (int)(ques[0]-48);
    string s = ques.substr(1,ques.length()-1);
    for(int i = 0 ; i < codes[idx].length();i++){
        printKPC(s,asf + codes[idx][i]);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}