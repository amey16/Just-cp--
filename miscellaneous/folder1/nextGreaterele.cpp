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
        
    stack<int> st;
    for(int i=0;i<n;i++){
        int value = arr[i];
        if(st.size() == 0)
            st.push(value);
        else{
            while(st.size()!=0 && st.top()<value){
                cout<<st.top()<<" --> "<<value<<endl;
                st.pop();
            }
            st.push(value);
        }
    }
    while(st.size() > 0){
        cout<<st.top()<<" --> "<<"-1"<<endl;
        st.pop();
    }
}