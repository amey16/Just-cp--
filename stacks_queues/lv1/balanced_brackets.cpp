#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int main(){
    string str;
    getline(cin,str);

    stack<char> st;
    for(int i=0; i<str.length();i++){
        char ch = str[i];
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        } 
        else if(ch == ')'){
            if (st.size() == 0 || st.top() != '(') {
                cout<<"false"<<endl;
                return 0;
            }else{
                st.pop();
            }
        }else if(ch == '}') {
            if(st.size() == 0 || st.top() != '{') {
                cout<<"false"<<endl;
                return 0;
            } else {
                st.pop();
            }
        }else if(ch == ']'){
            if(st.size() == 0 || st.top() != '[') {
                cout<<"false"<<endl;
                return 0;
            } else {
                st.pop();
            }
        }
    }

    if (st.size() == 0) {
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}