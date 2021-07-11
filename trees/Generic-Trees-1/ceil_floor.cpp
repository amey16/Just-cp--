#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<climits>
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
int ceile = INT_MAX;
int floore = INT_MIN;

void floor_ceil(Node* node,int data){
    if(node->data > data)
        if(node->data < ceile)
            ceile = node->data;
            
    if(node->data < data)
        if(node->data > floore)
            floore = node->data;
    
    for(Node* child:node->children)
        floor_ceil(child,data);
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
  
    floor_ceil(root1,data);
    cout<<"CEIL = "<<ceile<<endl;
    cout<<"FLOOR = "<<floore<<endl;
}