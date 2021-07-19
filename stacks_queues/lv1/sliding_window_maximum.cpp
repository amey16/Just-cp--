#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int k;
    cin>>k;
    
    vector<int> nge(n);
    stack<int> st;
    nge[n-1] = n;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[i] > arr[st.top()])
            st.pop();
        
        if(st.empty())
            nge[i] = n;
        else
            nge[i] = st.top();
            
        st.push(i);
    }
    int j = 0;
    for(int i = 0;i<=n-k;i++){
        if(j<i)
            j = i;
        while(nge[j] < i+k)
            j = nge[j];
        cout<<arr[j]<<endl;
    }
}