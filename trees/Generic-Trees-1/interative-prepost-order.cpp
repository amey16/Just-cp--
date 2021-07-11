// code not working for some reason
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<climits>
#include<string>
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

struct Pair{
    Node* node;
    int state;
};
Pair* newPair(Node* node,int state){
    Pair* temp1 = new Pair;
    temp1->state = state;
    temp1->node = node; 
    return temp1;
}

void pre_post(Node* node){
    stack<Pair*> st;
    st.push(newPair(node,-1));
    
    string pre = "";
    string post = "";
    while(!st.empty()){
        Pair* topele = st.top();
        st.pop();
        
        // Node* n = topele->node;
        // int s = topele->state; 
        if(topele->state == 1){
            pre = pre + to_string(topele->node->data) +" ";
            topele->state += 1;
        }
        else if(topele->state == topele->node->children.size()){
            post = post + to_string(topele->node->data)+" ";
            st.pop();
        }
        else{
            Pair* p = newPair(node->children[topele->state],-1);
            st.push(p);
            topele->state += 1;
        }
    }
    cout<<pre<<endl;
    cout<<post<<endl;
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
    pre_post(root1);
}