#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
        int val;
        Node *next;
        Node(int data){
            val = data;
            next = NULL;
        }
};

Node* rotate(Node* head, int k)
{
    
    if(head==NULL || head->next==NULL || k==0)return head;
    int len = 1;
    Node *curr = head;
    while(curr->next!=NULL){
        curr=curr->next;
        len++;
    }
    curr->next=head;
    k=k%len;
    k=len-k-1;
    curr=head;
    while(k--){
        curr=curr->next;
    }
    head=curr->next;
    curr->next=NULL;
    return head;
}
int main(){
    
    return 0;
}