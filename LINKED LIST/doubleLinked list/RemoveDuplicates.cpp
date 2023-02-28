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
            next=NULL;
            prev =NULL;
        }
};


Node * removeDuplicates(Node *head)
{
    Node * curr=head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data && curr->next->next==NULL){
            curr->next=NULL;
        }else if(curr->data==curr->next->data){
            Node *temp = curr->next->next;
            curr->next=temp;
            temp->prev=curr;
        }else{
            curr=curr->next;
        }
    }
    return head;
}
int main(){
    
    return 0;
}