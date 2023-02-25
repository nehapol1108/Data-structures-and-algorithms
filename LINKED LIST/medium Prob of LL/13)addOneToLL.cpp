#include<bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.youtube.com/watch?v=EQQ-5FmghRw&t=647s&ab_channel=Yogesh%26Shailesh%28CodeLibrary%29

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
};


Node *reverse(Node *head){
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        Node *temp = curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

//TC->O(n) + O(n) + O(n) ~ O(n)
//SC->O(1)
Node* addOne(Node *head) 
{
    Node *head2 = reverse(head);
    Node *curr = head2;
    int flag=1;
    while(curr!=NULL && flag==1){
        if(curr->next==NULL && curr->data==9){
            curr->data=1;
            Node *newnode = new Node(0);
            newnode->next=head2;
            head2=newnode;
            curr=curr->next;
        }else if(curr->data==9){
            curr->data=0;
            curr=curr->next;
        }else{
            curr->data=curr->data+1;
            curr=curr->next;
            flag=0;
        }
    }
    head2 = reverse(head2);
    return head2;
}
int main(){
    
    return 0;
}