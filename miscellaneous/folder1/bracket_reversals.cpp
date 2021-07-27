#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    cin>>str;
 
    stack<char> st;
    for(int i=0;i<str.length();i++){
        if(st.empty())
            st.push(str[i]);
        else{
            if(str[i] == '}' && st.top() == '{')
                st.pop();
            else
                st.push(str[i]);
        }
    }
    int len = 0;
    while(!st.empty() && st.top()!='}'){
        len++;
        st.pop();
    }
    // cout<<len<<endl;
    int num = (len+1)/2 + (st.size()+1)/2;
    cout<<num<<endl;
}