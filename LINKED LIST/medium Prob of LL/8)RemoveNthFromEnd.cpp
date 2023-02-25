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

//TC->O(n) SC->O(1)
int getNthFromLast(Node *head, int n)
{
       Node *slow=head;
       Node *fast=head;
       while(n>1 && fast->next!=NULL){
           fast=fast->next;
           n--;
       }
       if(n>1)return -1;
       while(fast->next!=NULL){
           slow=slow->next;
           fast=fast->next;
       }
       
       return slow->data;
}

//TC->O(n+n) ~ O(n) , SC->O(1)
Node* removeNthFromEnd(Node* head, int n) {
    Node *prev = NULL;
    Node *curr = head;
    int c=0;
    while(curr!=NULL){
        c++;
        curr = curr->next;
    }
    int num = c-n-1;
    int cc=0;
    curr = head;
    if(num==-1){
        head = head->next;
        return head;
    }
    while(cc!=num && curr!=NULL){
        curr = curr->next;
        cc++;
    }
    //here curr is the prev of node to be deleted
    curr->next = curr->next->next;
    return head;  
}
//TC->O(n) SC->O(1)
Node* removeNthFromEnd(Node* head, int n) {
    Node * start = new Node();
    start -> next = head;

    Node *slow = start;
    Node *fast = start;
    for(int i=1;i<=n;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL){
        fast = fast->next;
        slow= slow->next;
    }
    slow->next = slow->next->next;
    return start->next;  
}
 
int main(){
    
    return 0;
}