#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    stack<int> st;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    st.push(arr[arr.size()-1]);
    vector<int> newarr(n);
    newarr[n-1] = -1;
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty())
            newarr[i] = -1;
        else
            newarr[i] = st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++)
        cout<<newarr[i]<<endl;
}