#include<iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int data;
};
// adding in reverse
class NodeOperation{
    public:
        void pushNode(Node** head_ref,int val){
            Node* newnode = new Node();
            newnode->data = val;
            newnode->next = *head_ref; // link old list off the newnode
            *head_ref = newnode;
        }
        void printNode(Node* head){
            while(head!=NULL){
                cout<<head->data<<"->";
                head = head->next;
            }
            cout<<endl;
        }
        void printMiddle(Node* head){
            Node* slow = head;
            Node* fast = head;
            if(head!=NULL){
                while(fast!=NULL && fast->next!=NULL){
                    slow = slow->next;
                    fast = fast->next->next;
                }
                cout<<"Middle element = "<<slow->data<<endl;
            }
        }
};
int main(){
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    for(int i=5;i>0;i--){
        temp->pushNode(&head, i);
        temp->printNode(head);
        temp->printMiddle(head);
    }
}