#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    int k;
    cin>>k;
    
    for(int i=0;i<n;i++){
        if(q.size() < k)
            q.push(arr[i]);
        else{
            if(q.top() < arr[i]){
                // cout<<q.top()<<" ";
                q.pop();
                q.push(arr[i]);
            }
        }
    }
    // cout<<endl;
    while(!q.empty()){
        cout<<q.top()<<endl;
        q.pop();
    }
}