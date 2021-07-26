#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};
int size(Node *head){
    int len = 0;
    Node *temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void display(Node *head){
    
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node *head = NULL;
    string str;
    getline(cin,str);
    
    while(str != "quit"){
        if(str == "display")
            display(head);
        else if(str == "size")
            cout<<size(head)<<endl;
        else{
            int num = stoi(str.substr(8));
            
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
        getline(cin,str);
    }
    
}