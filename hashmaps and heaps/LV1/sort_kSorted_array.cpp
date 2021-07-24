#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    int k;
    cin>>k;
    
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++){
        if(q.size()<=k)
            q.push(arr[i]);
        else{
            cout<<q.top()<<endl;
            q.pop();
            q.push(arr[i]);
        }
    }
    while(!q.empty()){
        cout<<q.top()<<endl;
        q.pop();
    }
}