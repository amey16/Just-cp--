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

int msn;
int ms = INT_MIN;

int sumchild(Node* node){
    int sum=0;
    for(Node* child:node->children){
        int cs = sumchild(child);
        sum+=cs;
    }
    sum+= node->data;
    
    if(sum >ms){
        ms = sum;
        msn = node->data;
    }
    return sum;
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
  
    sumchild(root1);
    cout<<msn<<"@"<<ms<<endl;
}