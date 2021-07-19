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
    
    vector<int> lb(n),rb(n);
    stack<int> st;
    lb[0] = -1;
    st.push(0);
    
    for(int i=1;i<arr.size();i++){
        while(st.size() > 0 && arr[i] <= arr[st.top()])
            st.pop();
        
        if(st.empty())
            lb[i] = -1;
        else
            lb[i] = st.top();
        
        st.push(i);
    }
    
    stack<int> st1;
    rb[n-1] = n;
    st1.push(n-1);
    
    // cout<<n-1<<endl;
    for(int i=arr.size()-2;i>=0;i--){
        while(st1.size() > 0 && arr[i] <= arr[st1.top()])
            st1.pop();
        
        if(st1.empty())
            rb[i] = n;
        else
            rb[i] = st1.top();
        
        st1.push(i);
    }
    
    // for(int i=0;i<n;i++)
    //     cout<<lb[i]<<" ";
    // cout<<endl;
    
    // for(int i=0;i<n;i++)
    //     cout<<rb[i]<<" ";
    // cout<<endl;
    
    int maxarea = 0;
    for(int i=0;i<n;i++){
        int length = rb[i] - lb[i] - 1;
        int area = length*arr[i];
        if(area>maxarea)
            maxarea = area;
    }
    cout<<maxarea<<endl;
    
}