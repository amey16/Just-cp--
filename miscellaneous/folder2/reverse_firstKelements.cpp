#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int main(int argc,char** argv){
    int n;
    cin>>n;
    
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    
    int k;
    cin>>k;
    
    queue<int> q;
    stack<int> s;
    for(int i=0;i<n;i++)
        q.push(nums[i]);
    
    int temp;
    for(int i=0;i<k;i++){
        temp = q.front();
        q.pop();
        s.push(temp);
    }
    while(!s.empty()){
        temp = s.top();
        s.pop();
        q.push(temp);
    }
    for(int i=0;i<n-k;i++){
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}