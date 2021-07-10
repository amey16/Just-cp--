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
bool isSame(Node* node1,Node* node2){
    if(node1->children.size() != node2->children.size())
        return false;
    for(int i=0;i<node1->children.size();i++){
        Node* n1 = node1->children[i];
        Node* n2 = node2->children[i];
        
        if(isSame(n1,n2) == false)
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
    
    int n1;
    cin>>n1;
    vector<int> arr2(n1);
    for(int i=0;i<n1;i++)
        cin>>arr2[i];
    
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
    Node* root2 = newNode(arr2[0]);
    stack<Node*> st2;
    st2.push(root2);
    for(int i=1;i< arr2.size();i++){
        if(arr2[i] == -1){
            // if(!st2.empty())
                st2.pop();
        }
        else{
            Node* t = newNode(arr2[i]);
            (st2.top()->children).push_back(t);
            st2.push(t);
        }
    }
    
    // display(root1);
    // cout<<endl;
    // display(root2);
    
    if(isSame(root1,root2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}