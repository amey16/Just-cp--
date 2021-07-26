#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> stocks(n);
    for(int i=0;i<n;i++)
        cin>>stocks[i];
        
    stack<int> st;
    vector<int> spans(n);
    for(int i=stocks.size()-1;i>=0;i--){
        if(st.empty())
            st.push(i);
        else{
            while(!st.empty() && stocks[st.top()] < stocks[i]){
                spans[st.top()] = st.top() - i;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        spans[st.top()] = 1;
        st.pop();
    }
    
    for(int i=0;i<n;i++)
        cout<<spans[i]<<" ";
    cout<<endl;
}
