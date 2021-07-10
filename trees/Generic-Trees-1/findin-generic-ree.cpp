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
bool findIn(Node* node,int val){
    if(node->data == val)
        return true;
    for(Node* child:node->children){
        bool ans = findIn(child,val);
        if(ans)
            return true;
    }
    return false;
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
    int val;
    cin>>val;
    if(findIn(root,val))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    // display(root);
}