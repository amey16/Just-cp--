#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
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
void removeleaf(Node* node){
    for(int i = node->children.size()-1;i>=0;i--){
        Node* child = node->children[i];
        if(child->children.size() == 0){
            node->children.erase(node->children.begin() + i);
        }
    }
    for(Node* child:node->children)
        removeleaf(child);
}
void display(Node* node){
    string str = to_string(node->data) + " -> ";
    for(Node* child:node->children){
        str += to_string(child->data)+", ";
    }
    str +=".";
    cout<<str<<endl;
    for(Node* child: node->children)
        display(child);
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
    // display(root);
    removeleaf(root);
    display(root);
}