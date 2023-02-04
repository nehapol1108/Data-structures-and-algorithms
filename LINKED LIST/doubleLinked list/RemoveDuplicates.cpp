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

void removeDuplicates(node * &head)
{
    node *temp = head;
    while(temp->next!=NULL){
        if(temp->data==(temp->next->data) && temp->next->next==NULL){
            node * temp2 = temp->next->next;
            temp->next = temp2;
        }
        else if(temp->data==(temp->next->data)){
            node * temp2 = temp->next->next;
            temp->next = temp2;
            temp2->prev = temp;
        }else{
            temp = temp->next;  
        }
    }
}
int main(){
    node *head = NULL;
    InsertNodeAtTail(10, head);
    InsertNodeAtTail(10, head);
    InsertNodeAtTail(20, head);
    InsertNodeAtTail(20, head);
    InsertNodeAtTail(20, head);
    InsertNodeAtTail(30, head);
    InsertNodeAtTail(30, head);
    printLinkedList(head);
    removeDuplicates(head);
    printLinkedList(head);
    return 0;
}