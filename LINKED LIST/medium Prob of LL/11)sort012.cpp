#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev=NULL;
        }
        Node(){
            next = NULL;
            prev=NULL;
        }
};

//TC->O(N) SC->O(1)
Node* segregate(Node* head) {
    int c0=0,c1=0,c2=0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            c0++;
        }else if(temp->data==1){
            c1++;
        }
        else if(temp->data==2){
            c2++;
        }
        temp = temp->next;
    }
    temp = head;
    while(c0--){
        temp->data = 0;
        temp = temp->next;
    }
    while(c1--){
        temp->data = 1;
        temp = temp->next;
    }
    while(c2--){
        temp->data = 2;
        temp = temp->next;
    }
    return head;
} 

//TC->O(N) SC->O(1)
void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}
Node* segregate(Node* head) {
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    
    Node *twohead = new Node(-1);
    Node *twotail = twohead;
    
    Node *curr = head;
    while(curr!=NULL){
        if(curr->data==0){
            insertAtTail(zerotail,curr);
        }else if(curr->data==1){
            insertAtTail(onetail,curr);
        }else if(curr->data==2){
            insertAtTail(twotail,curr);
        }
        curr = curr->next;
    }
    if(onehead->next!=NULL){
        zerotail->next = onehead->next;
    }else{
        zerotail->next = twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;
    head = zerohead->next;
    delete onehead;
    delete zerohead;
    delete twohead;
    return head;
}  
int main(){
    
    return 0;
}