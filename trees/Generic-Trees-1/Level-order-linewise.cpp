#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stack>
using namespace std;

struct Node{
    int data;
    vector<Node*> children;
};
Node *newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    return temp;
}
void levelOrderlinewise(Node* node){
    queue<Node*> pq;
    queue<Node*> cq;
    
    pq.push(node);
    while(!pq.empty()){
        Node * ele = pq.front();
        pq.pop();
        
        cout<<ele->data<<" ";
        for(Node* child:ele->children){
            cq.push(child);
        }
        if(pq.empty()){
            cout<<endl;
            queue<Node*> temp;
            pq = cq;
            cq = temp;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    Node* root = newNode(arr[0]);
    stack<Node*> st;
    st.push(root);
    for(int i=1;i< arr.size();i++){
        if(arr[i] == -1){
            st.pop();
        }
        else{
            Node* t = newNode(arr[i]);
            (st.top()->children).push_back(t);
            st.push(t);
        }
    }
    levelOrderlinewise(root);
}