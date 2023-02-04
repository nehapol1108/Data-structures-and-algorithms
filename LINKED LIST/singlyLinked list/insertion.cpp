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

//insert at begining
node* InsertatFirst(int x,node *head){
    node *newnode = new node(x);
    if(head==NULL){
        return newnode;
    }
    newnode->next = head;
    head=newnode ;
    return newnode;
}
//insert at end
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

node* InsertAtPosition(int x,node *head,int pos){
    node *newnode = new node(x);
    node *temp = head;
    if(head==NULL){
        return newnode;
    }
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;

}
int main(){
    node * head = NULL; // head of the LinkedList
    head = InsertatFirst(40, head);
    head = InsertatFirst(30, head);
    head = InsertatFirst(20, head);
    head = InsertatFirst(10, head);
    cout << "LinkedList before inserting 8 at beginning : " << endl;
    printLinkedList(head);
    head = InsertatFirst(8, head);
    cout << "LinkedList after inserting 8 at beginning : " << endl;
    printLinkedList(head);
    head = InsertatLast(16, head);
    cout << "LinkedList after inserting 8 at ending : " << endl;
    printLinkedList(head);

    head = InsertAtPosition(50, head,3);
    cout << "LinkedList after inserting 50 at index 3 : " << endl;
    printLinkedList(head);

    return 0;
}