#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
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
bool isMirror(Node* node1,Node* node2){
    if(node1->children.size() != node2->children.size())
        return false;
    for(int i=0;i<node1->children.size();i++){
        int j = node1->children.size() - 1 - i;
        Node* n1 = node1->children[i];
        Node* n2 = node2->children[j];
        
        if(isMirror(n1,n2) == false)
            return false;
    }
    return true;
}
void display(Node* node){
    string str = to_string(node->data) + " -> ";
    for(Node* child:node->children){
        str += to_string(child->data)+",";
    }
    str +=".";
    cout<<str<<endl;
    for(Node* child: node->children)
        display(child);
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
  
    if(isMirror(root1,root1))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}