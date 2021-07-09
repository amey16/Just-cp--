#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<climits>
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
void traversal(Node* node){
    cout<<"Node Pre "<<node->data<<endl;
    for(Node *child:node->children){
        cout<<"Edge Pre "<<node->data<<"--"<<child->data<<endl;
        traversal(child);
        cout<<"Edge Post "<<node->data<<"--"<<child->data<<endl;
    }
    cout<<"Node Post "<<node->data<<endl;
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
    traversal(root);
}

