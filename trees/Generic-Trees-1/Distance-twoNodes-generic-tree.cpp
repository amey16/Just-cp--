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
vector<int> node_root(Node* node,int val){
    if(node->data == val){
        vector<int> ans;
        ans.push_back(node->data);
        return ans;
    }
    for(Node* child:node->children){
        vector<int> ans = node_root(child,val);
        if(ans.size()>0){
            ans.push_back(node->data);
            return ans;
        }
    }
    return {};
}
int dbn(Node* node,int v1,int v2){
    vector<int> a1 = node_root(node,v1);
    vector<int> a2 = node_root(node,v2);
    
    int i = a1.size()-1;
    int j = a2.size()-1;
    
    while(i>=0 && j>=0 && a1[i] == a2[j]){
        i--;j--;
    }
    return i+j+2;
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
    int val1,val2;
    cin>>val1;
    cin>>val2;
    
    cout<<dbn(root,val1,val2)<<endl;
}