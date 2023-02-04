#include<bits/stdc++.h>
#define ll long long
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int data){
            this->data = data;
            next = NULL;
        }
};
void printLinkedList(node *&head){
    node *curr = head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}

//insert at begining
void InsertatFirst(int x,node *&head){
    node *newnode = new node(x);
    if(head==NULL){
        head = newnode;
        head->next = head;
        return;
    }
    node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    } 
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
    
}
//insert at end
void InsertatLast(int x,node *&head){
    node *newnode = new node(x);
    node *temp = head;
    if(head==NULL){
        InsertatFirst(x,head);
        return;
    }
    while(temp->next!=head){
        temp = temp->next;
    } 
    newnode->next = head;
    temp->next = newnode;   
}
void deleteAtHead(int pos,node *&head){
    node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    } 
    node *todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}
void Deletion(int pos,node *&head){
    if(pos==1){
        deleteAtHead(pos,head);
        return;
    }
    node *temp = head;
    int count=1;
    while(count!=pos-1){
        temp = temp->next;
        count++;
    } 
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;   
}

int main(){
    node * head = NULL; // head of the LinkedList
    InsertatFirst(40, head);
    InsertatFirst(30, head);
    InsertatFirst(20, head);
    InsertatFirst(10, head);
    printLinkedList(head);
    Deletion(1,head);
    printLinkedList(head);
    Deletion(3,head);
    printLinkedList(head);

    return 0;
}