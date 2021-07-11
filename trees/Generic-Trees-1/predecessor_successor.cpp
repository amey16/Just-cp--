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
Node* p;
Node* s;
int state;

void presuc(Node* node,int data){
    if(state == 0){
        if(node->data == data)
            state = 1;
        else
            p = node;
    }
    else if(state == 1){
        s = node;
        state = 2;
    }
    
    for(Node* child:node->children)
        presuc(child,data);
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
    int data;
    cin>>data;
  
    state = 0;
    presuc(root1,data);
    if(p)
        cout<<"Predecessor = "<<p->data<<endl;
    else
        cout<<"Predecessor = Not found"<<endl;
    if(s)
        cout<<"Successor = "<<s->data<<endl;
    else
        cout<<"Successor = Not found"<<endl;
}