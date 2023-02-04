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

bool searchElement(node *head,int ele){
    if(head==NULL){
        return false;
    }
    node *temp = head;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==ele){
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1){
        return true;
    }
    return false;
}
int main(){
    node * head = NULL; // head of the LinkedList
    head = InsertatLast(40, head);
    head = InsertatLast(30, head);
    head = InsertatLast(20, head);
    head = InsertatLast(10, head);
    head = InsertatLast(50, head);
    printLinkedList(head);
    bool search = searchElement(head,4);
    bool search2 = searchElement(head,40);
    cout<<search<<" "<<search2<<endl;

    return 0;
}