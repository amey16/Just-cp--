#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};
int main(){
    Node *head = NULL;
    string str;
    getline(cin,str);
    
    int val;
    vector<int> values;
    while(str != "quit"){
        val = stoi(str.substr(8));
        values.push_back(val);
        getline(cin,str);
    }
    if(values.size() == 0){
        cout<<"0"<<endl;
        return 0;
    }
    // for(int  i=0;i<values.size();i++)
    //     cout<<values[i]<<" ";
    // cout<<endl;
    for(int  i=0;i<values.size();i++){
        int num = values[i];
        
        Node *newnode = new Node();
        newnode->data = num;
        newnode->next = NULL;
        
        if(head == NULL)
            head = newnode;
        else{
            Node *lastNode = head;
            while(lastNode->next != NULL)
                lastNode = lastNode->next;
            lastNode->next = newnode;
        }
    }
    int len = 0;
    // cout<<head->data<<endl;
    Node *temp = head;
    while(temp->next != NULL){
        len++;
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<temp->data<<endl;
    cout<<len+1<<endl;
    cout<<temp->data<<endl;
}