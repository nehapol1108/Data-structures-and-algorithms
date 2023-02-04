#include<bits/stdc++.h>
#define ll long long
using namespace std;
class node{
    public:
        int data;
        node *next;
        node *prev;
        node(int data){
            this->data = data;
            next=NULL;
            prev =NULL;
        }
};
void printLinkedList(node *head){
    node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void InsertatHead(int data,node * &head){
    node *newnode = new node(data);
    newnode->next = head;
    if(head!=NULL){  //as prev dont exist for null
        head->prev = newnode;
    }
    head = newnode ;

}
void InsertNodeAtTail(int data,node * &head){
    if(head==NULL){
        InsertatHead(data,head);
        return;
    }
    node *newnode = new node(data);
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;
    return;   
}
void deleteatHead(node * &head){
    node * temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;


}
void deleteNode(int pos,node * &head){
    if(pos==0){
        deleteatHead(head);
        return;
    }
    node *temp = head;
    int count=0;
    while(temp!=NULL && count!=pos-1){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    return;   
}
// Given a doubly-linked list, a position p, and an integer x. 
// The task is to add a new node with value x at the position just after pth node in the doubly linked list.
void addNode(node *head, int pos, int data)
{
    node *newnode = new node(data);
    int count=0;
    node *temp = head;
    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    if(temp->next!=NULL){
         temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
   // cout<<temp->data<<endl;
   
}
// Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.
node* deleteNode(node *head, int x)
{
    node *temp = head;
    int count=1;
    if(x==1){
        head=head->next;
        head->prev=NULL;
        return head;
        
    }
    while(temp!=NULL && count!=x){
        count++;
        temp=temp->next;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    return head;   
}



int main(){
    node *head = NULL;
    InsertNodeAtTail(20, head);
    InsertNodeAtTail(40, head);
    InsertNodeAtTail(30, head);
    InsertNodeAtTail(20, head);
    InsertNodeAtTail(20, head);
    InsertNodeAtTail(10, head);
    InsertNodeAtTail(20, head);
    printLinkedList(head);
   // cout<<head->data<<endl;
    printLinkedList(head);
    return 0;
}