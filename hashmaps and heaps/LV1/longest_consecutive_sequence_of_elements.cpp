#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int,bool> m;
    int c;
    for(int i=0;i<n;i++){
        cin>>c;
        if(m.find(c) == m.end())
            m[c] = true;
    }
    for(auto itr = m.begin();itr!=m.end();itr++){
        if(m.find(itr->first+1) == m.end())
            m[itr->first] = false;
    }
    int mlen = 0,ms =0;
    for(auto itr = m.begin();itr!=m.end();itr++){
        int len = 0;
        if(itr->second == true){
            int i = itr->first;
            while(m.find(i) != m.end()){
                len++;
                i++;
            }
            if(mlen<len){
                ms = itr->first;
                mlen = len; 
            }
            if(mlen == len && ms > itr->first){
                ms = itr->first;
            }
        }
    }
    for(int i=0;i<mlen;i++){
        cout<<ms+i<<endl;
    }
}