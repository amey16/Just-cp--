#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    // write your code here
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }
    if(str.length()==1){
        int no = str[0] - 48;
        if(no==0)
            return;
        else{
            string s = str.substr(1,str.length()-1);
            asf = asf + (char)(no+96);
            cout<<asf<<endl;
        }
    }
    else{
        int no = str[0] - 48;
        if(no == 0)
            return;
        else{
            string s = str.substr(1,str.length()-1);
            printEncoding(s,asf + (char)(no+96));
        }
        
        int no1 = (str[0] - 48) *10 + (str[1]-48);
        if(no1>=10 && no1<=26){
            string s = str.substr(2,str.length()-2);
            printEncoding(s,asf + (char)(no1+96));
        }
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}