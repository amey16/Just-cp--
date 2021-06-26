#include<iostream>
#include<vector>
using namespace std;

void combinations(vector<bool> boxes, int ci, int ti, int lb){
    // write your code here
    if(ci>ti){
        for(int i = 0 ;i<boxes.size();i++){
            if(boxes[i] == true)
                cout<<"i";
            else
                cout<<"-";
        }
        cout<<endl;
        return;
    }
    for(int b = lb+1;b< boxes.size();b++){
        if(boxes[b] == false){
            boxes[b] = true;
            combinations(boxes,ci+1,ti,b);
            boxes[b] = false;
        }
    }
    
}

int main(){
    int nitems,nboxes;
    cin>>nboxes;
    cin>>nitems;
    vector<bool> a(nboxes,false);
    combinations(a, 1, nitems, -1);
}