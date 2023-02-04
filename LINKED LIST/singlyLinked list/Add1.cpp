#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            data = data;
            next = NULL;
        }
};
Node *reverse(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
Node* addOne(Node *head) 
{

Node *head2 = reverse(head);
Node *curr = head2;
int flag=1;
while(curr!=NULL && flag==1){
    if(curr->next==NULL && curr->data==9){
        curr->data =1;
        Node *newnode= new Node(0);
        newnode->next=head2;
        head2=newnode;
        curr = curr->next;
    }
    else if(curr->data==9){
        curr->data = 0;
        curr = curr->next;
    }
    else {
        curr->data = curr->data +1;
        curr = curr->next;
        flag=0;
    }
}
head = reverse(head2);
return head;
}
//mysolnn
Node* addOne(Node *head) 
{
    Node *curr = head;
    Node *head2 = head;
    Node *prev = NULL;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        head2=curr;
        curr = temp;
    }
    curr = head2;
    int flag=0;
    while(curr!=NULL){
        int val=-1;
        if(curr->next==NULL && curr->data==9){
            val = 9;
        }
        if(curr->data<9 && flag==0 && curr==head2){
            curr->data = curr->data+1;
            break;
        }
        else if(curr->data<9 && flag==1){
            curr->data = curr->data+1;
            flag=0;
        }else if(curr->data==9 && flag==1){
            curr->data = 0;
            flag=1;
        }
        else if(curr->data==9 && curr==head2){
            curr->data = 0;
            flag=1;
        }
        if(val==9 && flag==1){
                Node *newnode= new Node(1);
                curr->next = newnode;
                curr = newnode;
                curr->next=NULL;
                head=newnode;
        }
        curr = curr->next;
    }
    curr = head2;
    prev = NULL;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return head;
}
int main(){
    
    return 0;
}