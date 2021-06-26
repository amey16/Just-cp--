#include<iostream>
#include<vector>
#include<string>
using namespace std;

void permutations(int cb, int tb,vector<int> items, int ssf, int ts, string asf){
    // write your code here
    if(cb > tb){
        if(ssf == ts)
            cout<<asf<<endl;
        return;
    }
    
    for(int item = 1 ; item <= ts ; item++ ){
        if(items[item-1] == 0){
            items[item-1] = 1;
            permutations(cb+1,tb,items,ssf+1,ts,asf+to_string(item));
            items[item-1] = 0;
        }
    }
    permutations(cb+1,tb,items,ssf,ts,asf+"0");
}

int main(){
    int nitems,nboxes;
    cin>>nboxes;
    cin>>nitems;
    vector<int> a(nboxes,0);
    permutations(1,nboxes,a, 0, nitems,"");
}