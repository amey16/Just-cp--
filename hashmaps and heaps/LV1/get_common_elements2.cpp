#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1;
    unordered_map<int,int> m1;
    int c;
    for(int i=0;i<n1;i++){
        cin>>c;
        if(m1.find(c) == m1.end())
            m1[c] = 1;
        else 
            m1[c] ++;
    }
    cin>>n2;
    for(int i=0;i<n2;i++){
        cin>>c;
        if(m1.find(c) != m1.end()){
            if(m1[c] == 1)
                m1.erase(c);
            else
                m1[c]--; 
            cout<<c<<endl;
        }
    }
}