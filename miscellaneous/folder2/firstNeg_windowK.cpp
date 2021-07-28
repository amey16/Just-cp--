#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(int argc,char** argv){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int k;
    cin>>k;
    
    queue<int> q;
    int i =0 ;
    while(i<k){
        if(arr[i]<0)
            q.push(i);
        i++;
    }
    
    while(i<n){
        if(!q.empty())
            cout<<arr[q.front()]<<" ";
        else 
            cout<<"0"<<" ";
            
        while(!q.empty() && q.front() < i-k+1){
            q.pop();
        }
        if(arr[i]<0)
            q.push(i);
        i++;
    }
    if(!q.empty())
           cout<<arr[q.front()]<<" ";
    else
        cout<<"0"<<" ";
}