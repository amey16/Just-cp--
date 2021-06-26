#include<iostream>
#include<vector>
using namespace std;

void permutations(vector<int> boxes, int ci, int ti){
    // write your code here
    if(ci>ti){
        for(int i = 0 ;i<boxes.size();i++)
            cout<<boxes[i];
        cout<<endl;
        return;
    }
    for(int b = 0 ;b<boxes.size();b++){
        if(boxes[b] == 0){
            boxes[b] = ci;
            permutations(boxes,ci+1,ti);
            boxes[b] = 0;
        }
    }
    
}

int main(){
    int nitems,nboxes;
    cin>>nboxes;
    cin>>nitems;
    vector<int> a(nboxes,0);
    permutations(a, 1, nitems);
}