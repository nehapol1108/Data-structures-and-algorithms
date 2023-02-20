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
// 1) At the front of the DLL 
// Time Complexity: O(1)
// Auxiliary Space: O(1)
void InsertatHead(int data,node * &head){
    node *newnode = new node(data);
    if(head==NULL){
        head=newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode ;
}

// 2) Add a node after a given node:
// Time Complexity: O(1)
// Auxiliary Space: O(1)
void InsertAfterNode(int data,node * &head,node *givenNode){
    node *newnode = new node(data);
    if(head==NULL){
        head=newnode;
        return;
    }
    newnode->next=givenNode->next;
    givenNode->next=newnode;
    newnode->prev = givenNode;
    if(newnode->next->prev!=NULL){
        newnode->next->prev=newnode;
    } 
    return;
}

// 3) Add a node at the end:
// Time Complexity: O(n)
// Auxiliary Space: O(1)
void InsertNodeAtTail(int data,node * &head){
    node *newnode = new node(data);
    if(head==NULL){
        head=newnode;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;
    return;   
}

// 4) Add a node before the given node
// Time Complexity: O(1)
// Auxiliary Space: O(1)
void InsertBeforeNode(int data,node* &head,node *givenNode){
    node *newnode = new node(data);
    if(givenNode==NULL){
        cout<<"Node cannot be inserted before a NULL";
        return;
    }
    newnode->prev=givenNode->prev;
    givenNode->prev=newnode;
    newnode->next=givenNode; 
    if(newnode->prev!=NULL){
        newnode->prev->next = newnode;
    }else{
        head = newnode;
        return;
    }
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
// Time Complexity: O(1). 
// Since traversal of the linked list is not required so the time complexity is constant.
// Auxiliary Space: O(1). 
// As no extra space is required, so the space complexity is constant.
node* deleteNode(node *head, int x)
{
    node *temp = head;
    int count=1;
    //to handle the first node delete case
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
    //to handle the last node case
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    return head;   
}



int main(){
    node *head = NULL;
    // InsertNodeAtTail(20, head);
    // InsertNodeAtTail(40, head);
    // InsertNodeAtTail(30, head);
    // InsertNodeAtTail(20, head);
    // InsertNodeAtTail(20, head);
    // InsertNodeAtTail(10, head);
    // InsertNodeAtTail(20, head);
    InsertatHead(20, head);
    InsertatHead(20, head);
    InsertatHead(30, head);
    InsertatHead(10, head);
    node *temp = head->next;
    InsertAfterNode(50,head,temp);
    printLinkedList(head);
   // cout<<head->data<<endl;
    printLinkedList(head);
    return 0;
}