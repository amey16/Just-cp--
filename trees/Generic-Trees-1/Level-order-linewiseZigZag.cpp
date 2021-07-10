#include<iostream>
#include<vector>
#include<queue>
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
    stack<Node*> pq;
    stack<Node*> cq;
    int lv = 0;
    pq.push(node);
    while(!pq.empty()){
        Node * ele = pq.top();
        pq.pop();
        
        cout<<ele->data<<" ";
        if(lv%2 == 0){
            for(Node* child:ele->children){
                cq.push(child);
            }
        }
        else{
            for(int i=ele->children.size()-1;i>=0;i--)
                cq.push(ele->children[i]);
        }
        if(pq.empty()){
            lv += 1;
            cout<<endl;
            stack<Node*> s;
            pq = cq;
            cq = s;
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