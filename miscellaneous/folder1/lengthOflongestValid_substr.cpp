#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

int main(){
    string str;
    cin>>str;
    
    stack<char> st;
    int len = 0;
    for(int i=0;i<str.length();i++){
        if(st.empty()){
            if(str[i]=='(')
                st.push(str[i]);
        }
        else{
            if(str[i]=='(')
                st.push(str[i]);
            else{
                len+=2;
                st.pop();
            }
        }
    }
    cout<<len<<endl;
}