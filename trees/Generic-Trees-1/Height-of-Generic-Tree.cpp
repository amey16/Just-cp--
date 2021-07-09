#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<climits>
#include<algorithm>
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
int height(Node* node){
    int h = -1;
    for(Node *child:node->children){
        int hm = height(child);
        h = max(h,hm);
    }
    h+=1;
    return h;
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
    cout<<height(root)<<endl;
}
