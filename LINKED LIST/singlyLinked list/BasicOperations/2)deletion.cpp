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
void printLinkedList(node *head){
    node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

node* InsertatLast(int x,node *head){
    node *newnode = new node(x);
    node *temp = head;
    if(head==NULL){
        return newnode;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    } 
   newnode->next = NULL;
    temp->next = newnode;
    return head;
}
void deleteNode(node *head,int pos){
    if(pos==1){
        head = head->next;
        return;
    }
    node *prev = head;
    for(int i=1;i<pos-1;i++){
        prev = prev->next;
    }
    prev->next = prev->next->next; 
}
void deleteNodeele(node *head,int ele){
    node *prev = head;
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHeadEle(head);
        return;
    }
    while(prev->next->data !=ele){
        prev = prev->next;
    }
    node *todelete = prev->next;
    prev->next = prev->next->next; 
    delete todelete;
}
void deleteAtHeadEle(node * &head){
    node *todelete = head;
    head = head->next;
    delete todelete;

}

int main(){
    node * head = NULL; // head of the LinkedList
    head = InsertatLast(40, head);
    head = InsertatLast(30, head);
    head = InsertatLast(20, head);
    head = InsertatLast(10, head);
    head = InsertatLast(50, head);
    printLinkedList(head);
    deleteNode(head,3);
    printLinkedList(head);
    deleteAtHeadEle(head);
    printLinkedList(head);

    deleteNodeele(head,20);
    printLinkedList(head);

    return 0;
}