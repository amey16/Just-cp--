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
int maxi(Node* node){
    int maximum = INT_MIN;
    for(Node *child:node->children){
        int cm = maxi(child);
        maximum = max(maximum,cm);
    }
    maximum = max(maximum,node->data);
    return maximum;
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
    cout<<maxi(root)<<endl;
}