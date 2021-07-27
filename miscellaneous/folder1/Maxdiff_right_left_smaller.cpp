#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

int mod(int a,int b){
    return b>=a?(b-a):(a-b);
}
int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    stack<int> st;
    vector<int> leftMin(n);
    vector<int> rightMin(n);
    for(int i=n-1;i>=0;i--){
        if(st.empty())
            st.push(i);
        else{
            while(!st.empty() && arr[st.top()] > arr[i]){
                leftMin[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        leftMin[st.top()] = 0;
        st.pop();
    }
    
    for(int i=0;i<n;i++){
        if(st.empty())
            st.push(i);
        else{
            while(!st.empty() && arr[st.top()] > arr[i]){
                rightMin[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        rightMin[st.top()] = 0;
        st.pop();
    }
    
    // for(int i=0;i<n;i++)
    //     cout<<leftMin[i]<<" ";
    // cout<<endl;
    
    // for(int i=0;i<n;i++)
    //     cout<<rightMin[i]<<" ";
    // cout<<endl;
    
    int maxdiff = INT_MIN;
    for(int i=0;i<n;i++){
        if(maxdiff < mod(leftMin[i],rightMin[i]))
            maxdiff = mod(leftMin[i],rightMin[i]);
    }
    cout<<maxdiff<<endl;
}
