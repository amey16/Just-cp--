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
            Node *ptr1 = new Node();
            Node *temp = *head_ref; 
            ptr1->data = val; 
            ptr1->next = *head_ref; 

            if(*head_ref != NULL){ 
                while(temp->next != *head_ref) 
                temp = temp->next;     
                temp->next = ptr1; 
            } 
            else
                ptr1->next = ptr1;
              
            *head_ref = ptr1;
        }
        void printNode(Node* head){
            Node *temp = head; 
            if(head != NULL){
                cout << endl; 
                do{ 
                    cout << temp->data << " "; 
                    temp = temp->next; 
                }while(temp != head); 
            } 
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
        void splitList(Node *head, Node **head1_ref,Node **head2_ref){ 
            Node *slow_ptr = head; 
            Node *fast_ptr = head; 
              
            if(head == NULL)
                return; 
        
            while(fast_ptr->next != head && fast_ptr->next->next != head){ 
                fast_ptr = fast_ptr->next->next; 
                slow_ptr = slow_ptr->next; 
            }
            if(fast_ptr->next->next == head) 
                fast_ptr = fast_ptr->next; 
        
            *head1_ref = head; 
        
            if(head->next != head) 
                *head2_ref = slow_ptr->next; 
                
            fast_ptr->next = slow_ptr->next; 
            slow_ptr->next = head; 
        } 
};
int main(){
    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;
    NodeOperation* temp = new NodeOperation();
    for(int i=5;i>0;i--){
        temp->pushNode(&head, i);
        // temp->printNode(head);
    }
    // cout<<endl;
    temp->splitList(head,&head1,&head2);
    temp->printNode(head1);
    temp->printNode(head2);
}