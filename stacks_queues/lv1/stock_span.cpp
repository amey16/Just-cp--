#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<int> ans(n);
    stack<int> st;
    ans[0] = 1;
    st.push(0);
    
    for(int i=1;i<arr.size();i++){
        while(!st.empty() && arr[i] > arr[st.top()])
            st.pop();
        
        if(st.empty())
            ans[i] = i+1;
        else
            ans[i] = i - st.top();
        
        st.push(i);
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
    // cout<<endl;
    
}