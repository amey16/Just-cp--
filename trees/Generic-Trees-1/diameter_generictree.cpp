#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<climits>
using namespace std;

struct Node{
    int data;
    vector<Node*> children;
};
Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    return temp;
}

int dia = 0;
int diacal(Node* node){
    int dch = -1;
    int sdch = -1;
    for(Node* child:node->children){
        int ch = diacal(child);
        if(ch>dch){
            sdch = dch;
            dch = ch;
        }
        else if(ch > sdch){
            sdch = ch;
        }
    }
    if(dch+sdch+2 > dia)
        dia = dch + sdch + 2;
    dch += 1;
    return dch;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++)
        cin>>arr1[i];
        
    Node* root1 = newNode(arr1[0]);
    stack<Node*> st1;
    st1.push(root1);
    for(int i=1;i< arr1.size();i++){
        if(arr1[i] == -1){
            st1.pop();
        }
        else{
            Node* t = newNode(arr1[i]);
            (st1.top()->children).push_back(t);
            st1.push(t);
        }
    }
  
    diacal(root1);
    cout<<dia<<endl;
}